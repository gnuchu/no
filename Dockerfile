FROM ubuntu:latest

RUN apt-get update
RUN apt-get update && apt-get -y install build-essential libtool automake pkg-config git wget gettext-base
ENV builddir='/tmp/builddir'
COPY . ${builddir}

WORKDIR ${builddir}
RUN make