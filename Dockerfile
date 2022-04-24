FROM debian
COPY programFORlab3C++ASM.cpp .
RUN apt-get update 
RUN apt-get install -y gcc
RUN apt-get install -y g++
RUN g++ programFORlab3C++ASM.cpp -static
CMD ./a.out 
