FROM debian:buster
# 대부분의 경우 안정성을 위해 리눅스 이미지에서 이미지 생성을 시작

RUN apt-get update && apt-get -y upgrade && \
	apt-get -y install nginx openssl && \
	mkdir -p /etc/ssl && \
	openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Gam/CN=jeyoon.42.fr" -keyout /etc/ssl/jeyoon.42.fr.key -out /etc/ssl/jeyoon.42.fr.pem
# 필요한 패키지 설치, 개인키와 self-signed 인증서 생성
# apt-get update : 설치 가능한 "리스트" 업데이트
# apt-get upgrade : 기존에 설치된 것들을 최신 버전으로 업그레이드
# openssl : TLS/SSL 구현한 오픈소스
# req : 인증 생성 요청을 처리하는 커맨드
# -newkey : arg 형식에 맞는 개인키 생성
# -days : 인증서의 유효기간 (기본 30일)
# -nodes : 생성한 개인키를 암호화하지 않음 (암호화하면 구동시에 암호를 물어본다고함)
# -x509 : self-signed 인증서 생성
# -subj : 인증서 내 정보를 인자로 입력
# -keyout, -out : 개인키를 적을 파일 지정, 인증서 저장 파일 지정

COPY conf/default.conf /etc/nginx/conf.d/default.conf
COPY tools/setup.sh .
# 설정 파일, 스크립트 복사

RUN chmod +x setup.sh

EXPOSE 443
# 컨테이너의 port open

ENTRYPOINT ["sh", "/setup.sh"]
# 이미지 빌드 후 스크립트 실행