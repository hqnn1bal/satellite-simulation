FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    build-essential cmake git wget unzip \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . /app

RUN cmake -B build -S . && cmake --build build -j4

EXPOSE 8000
WORKDIR /app/build

ENV EARTH_HOST=earth
ENV EARTH_PORT=8001

CMD ["./satellite_main"]
