FROM gcc:13
WORKDIR /app
COPY test1.cpp .
RUN g++ -o test1 test1.cpp
CMD ["./test1"]
