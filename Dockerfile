# Use Ubuntu 20.04 as the base image
FROM ubuntu:20.04 as builder

# Install build tools and required libraries
RUN apt-get update && \
    apt-get install -y g++ && \
    rm -rf /var/lib/apt/lists/*

# Set the working directory in the container
WORKDIR /app

# Copy the C++ source files to the container
COPY . /app

# Compile the C++ code
RUN g++ -o Bank banking.cpp

# Stage 2: Create a minimal runtime image
FROM debian:latest

# Set the working directory in the container
WORKDIR /app

# Copy the compiled binary from the builder stage
COPY --from=builder /app/Bank /app/

# Expose any necessary ports (if applicable)
# EXPOSE 8080

# Command to run the binary
CMD ["./Bank"]
