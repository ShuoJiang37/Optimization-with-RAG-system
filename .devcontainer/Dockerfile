FROM debian:stable-slim

RUN apt-get update && apt-get install -y --no-install-recommends \
    bash \
    build-essential \
    linux-perf \
    git \
    zip \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*
