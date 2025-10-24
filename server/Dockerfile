FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    build-essential cmake git wget curl unzip \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . /app

RUN cmake -B build -S . && cmake --build build -j4

EXPOSE 8080

WORKDIR /app/build

ENV SATELLITE_HOST=satellite
ENV SATELLITE_PORT=8000

CMD ["./server-main"]
