# Auto_Commit.sh


### Description
* 자동으로 파일을 생성해 랜덤한 시간에 하루 한 번 커밋하는 bash shell scrpit.
* 1일 1커밋이 유행이라길래 [다른 계정](https://github.com/collinahn01)에 시험해보려고 만들었다. (현재는 중단됨)
* (상시 동작하는 서버가 필요함)

### Environment
* Ubuntu 18.04
* systemd 서비스 등록

### Prerequisite
* bash shell
* gcc version 8.3.0

### Files
* auto_commit.sh
  * 랜덤한 시간 및 날짜 생성 후 해당 시각이 되면 자동으로 생성한 파일을 커밋 메시지와 함께 커밋하고 레포지토리에 푸시한다.
  * 작업을 완료했으면 날짜가 넘어갈 때 까지 쉰다.  

### Usage

* getNextDay.c 컴파일
```
$ gcc -o getNextDayExe -fPIC -Wall getNextDay.c
```
* 단독으로 디버깅하려면(단독 실행 아닐경우 플래그 빼고 컴파일 필요)
```
$ gcc -o getNextDayExe -fPIC -Wall getNextDay.c -D_DEBUG_
```

* 서비스 등록
```
$ sudo vi /etc/systemd/system/{servicename}.service
```
* 다음과 같은 내용 입력 후 저장
```
[Unit]
Description={description}
After=network.target

[Service]
Type=idle
ExecStart={file path}
WorkingDirectory={path}
Restart=always
User={username}

[Install]
WantedBy=multi-user.target
```
* 서비스 등록 및 시작
```
$ sudo systemctl daemon-reload
$ sudo systemctl enable {service name}
$ sudo systemctl start {service name}
```
* 상태 확인
```
$ sudo systemctl status {service name}
```
* 자세한 상태 확인
```
$ sudo journalctl -u {service name} -n {amount of log}
```

* git remote repository에 ssh로 인증하는 방법)
  * 1. ssh-gen으로 공개 키를 만든다
  ```
  $ ssh-keygen -C "email@address" -t rsa -b 4096 -f git_rsa
  ```

  * 2. git 계정에 등록한다
  * 3. remote저장소 업데이트
  ```
  $ git remote rm origin
  $ git config --global remote.origin.url git@github.com:~(주소)
  $ git push --set-upstream origin main
  ```


* 아래와 같은 에러가 있을 시 해결 방안과 같이 해결:
```
git@github.com: Permission denied (publickey).
fatal: Could not read from remote repository.

Please make sure you have the correct access rights
and the repository exists.
```

* 해결 방안)
```
$ eval $(ssh-agent)
$ ssh-add ~/.ssh/git_rsa
```


### Update Log
* 2021.07.30
  * 생성
* 2021.07.31
  * 달이 넘어갈 때 기존의 방식으로는 정상 동작하지 않아 날을 계산하는 프로그램 추가 
