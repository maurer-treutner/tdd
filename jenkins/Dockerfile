FROM jenkins/jenkins:lts

USER root

RUN apt-get update
RUN apt-get install -y build-essential
RUN apt-get install -y libstdc++-6-dev
RUN apt-get install -y cmake
RUN apt-get install -y git
RUN apt-get install -y libboost-test-dev
RUN apt-get install -y python