FROM ubuntu:18.04

#install packages from apt (when image is built)  
RUN apt-get update
RUN apt-get install -y build-essential
RUN apt-get install -y libstdc++-7-dev
RUN apt-get install -y cmake
RUN apt-get install -y git
RUN apt-get install -y libboost-test-dev
RUN apt-get install -y python

#mount /project to a path given from host
VOLUME /project

# Executed when image is started
# Aktullen ihalt in project kopieren
COPY . /project
# Build step in container
CMD cd /project && ./build.sh
