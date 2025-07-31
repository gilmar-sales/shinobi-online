
FROM ubuntu:latest AS build

ARG CACHEBUST=$(sha256sum conandata.yml | awk '{print $1;}')

WORKDIR /workspace

COPY . .

RUN apt update && apt install -y python3 pipx build-essential cmake ninja-build
RUN pipx ensurepath
RUN pipx install conan

# prevent cache
ARG CACHEBUST=$(git rev-parse main)

# generate and build
RUN export PATH=/root/.local/bin:$PATH && cmake -DCMAKE_BUILD_TYPE:STRING=Release \
    -DCMAKE_PROJECT_TOP_LEVEL_INCLUDES="conan_provider.cmake" \
    -H/workspace -B/workspace/build -G Ninja

RUN cmake --build /workspace/build --config Release --target all -j 6

COPY /workspace/build/src/server /workspace

FROM build AS server

ENV VCPKG_ROOT=/workspace/vcpkg
WORKDIR /workspace

COPY --from=build /workspace/data/ /workspace/mods/ /workspace/config.lua /workspace/server /workspace/.git/ /workspace/

CMD [ "/workspace/server" ] 