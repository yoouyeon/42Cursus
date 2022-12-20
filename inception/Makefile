COMPOSE = docker compose
COMPOSE_FILE = ./srcs/docker-compose.yml
LOCAL_VOLUME_DB = /home/jeyoon/data/mariadb
LOCAL_VOLUME_WP = /home/jeyoon/data/wordpress

all: up

up:
	mkdir -p $(LOCAL_VOLUME_DB)
	mkdir -p $(LOCAL_VOLUME_WP)
	bash -c "echo '127.0.0.1       jeyoon.42.fr' >> /etc/hosts"
	$(COMPOSE) -f $(COMPOSE_FILE) up --build

# up : 실행 명령어
# --build : 이미지를 빌드한 뒤에 실행한다. (이미지를 빌드하지 않는 -no-build 옵션도 있음)
# 변경사항이 있는 이미지들을 새로 빌드하고
# 컨테이너를 실행 / 이미 실행중인 컨테이너들은 그대로 둔다

down:
	$(COMPOSE) -f $(COMPOSE_FILE) down --remove-orphans --volumes

# down : 종료 명령어
# 컴포즈 파일에 정의된 컨테이너 삭제 (기본)
# 컴포즈 파일에 정의된 네트워크 삭제 (기본)
# --remove-orphans : 정의되지 않은 컨테이너도 삭제
# --volumes : 정의된 볼륨들 삭제

clean:
	$(COMPOSE) -f $(COMPOSE_FILE) down --remove-orphans --rmi all --volumes

# --rmi all : 모든 이미지들도 삭제

fclean: clean
	@ docker image prune --force
	@ docker network prune --force
	@ docker volume prune --force
	rm -rf $(LOCAL_VOLUME_DB)/*
	rm -rf $(LOCAL_VOLUME_WP)/*
# 이미지와 볼륨 삭제


re: fclean all
.PHONY: all down clean fclean re