FROM ubuntu:18.04
  
RUN apt-get update
RUN apt-get install -y gcc
RUN apt-get install -y cmake
RUN apt-get install -y git
RUN apt-get install -y libboost-test-dev

COPY . /project

CMD cd project && git fetch
CMD cd project && build.sh