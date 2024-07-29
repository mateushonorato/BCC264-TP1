FROM alpine:latest
RUN apk add --no-cache psmisc gcc g++ vim grep make
COPY media/MateusHonorato.txt /MateusHonorato/
COPY src /MateusHonorato/src/
COPY Makefile /MateusHonorato
RUN cd /MateusHonorato && make all