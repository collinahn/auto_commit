# Auto_Commit.sh


### Description
* 자동으로 파일을 생성해 랜덤한 시간에 하루 한 번 커밋하는 bash shell scrpit.
* 1일 1커밋이 유행이라길래 [다른 계정](https://github.com/collinahn01)에 시험해보려고 만들었다.
* (상시 동작하는 서버가 필요함)

### Environment
* Ubuntu 18.04
* systemd 서비스 등록하여 사용

### Prerequisite
* bash shell

### Files
* auto_commit.sh
  * 랜덤한 시간 및 날짜 생성 후 해당 시각이 되면 자동으로 생성한 파일을 커밋 메시지와 함께 커밋하고 레포지토리에 푸시한다.
  * 작업을 완료했으면 날짜가 넘어갈 때 까지 쉰다.  

### Usage
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
$ sudi journalclt -u {service name} -n {amount of log}
```

