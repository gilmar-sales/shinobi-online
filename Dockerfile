
FROM kuyoh/vcpkg:latest AS vcpkg-install

ARG CACHEBUST=$(sha256sum vcpkg.json | awk '{print $1;}')

ENV VCPKG_ROOT=/workspace/vcpkg
WORKDIR /workspace

COPY . .

RUN apt update && apt install -y bison flex python3 libltdl-dev

RUN ./vcpkg/vcpkg install

# prevent cache
ARG CACHEBUST=$(git rev-parse main)

# generate and build
RUN cmake -DCMAKE_BUILD_TYPE:STRING=Release \
    -H/workspace -B/workspace/build -G Ninja

RUN cmake --build /workspace/build --config Release --target all -j 6

COPY /workspace/build/src/server /workspace

FROM vcpkg-install AS server

ENV VCPKG_ROOT=/workspace/vcpkg
WORKDIR /workspace

COPY --from=vcpkg-install /workspace/data/ /workspace/mods/ /workspace/config.lua /workspace/server /workspace/.git/ /workspace/

CMD [ "/workspace/server" ] 