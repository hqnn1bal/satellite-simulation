FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . /app

RUN cmake -B build -S . && cmake --build build -j4

EXPOSE 8001
WORKDIR /app/build

CMD ["./earth_main"]
