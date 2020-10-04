# DNS-IOT (SmallDNS)

### 구현 언어
![](https://upload.wikimedia.org/wikipedia/commons/thumb/1/18/ISO_C%2B%2B_Logo.svg/220px-ISO_C%2B%2B_Logo.svg.png)

### 진행상황
| 차시 | 날짜 | 구현내용 |
|:---:|:---:|:---|
| 1차 | 2020-10-06 | 기본적인 동작을 하는 DNS Server를 Single Thread Iterative Server로 구현. |

### 컨벤션
#### `DNS Server`
해당 프로그램을 의미한다.
#### `Client`
해당 DNS Server 서비스의 이용자를 의미한다..
#### `DB`
해당 프로그램에서 사용하는 DBMS인 MySQL를 의미한다.
#### `Host 정보`
도메인 이름, IP 주소 리스트, Alias 리스트 정보를 의미한다.
#### `Hit Count`
`Client`가 해당 `DNS Server`에 특정 도메인에 대한 정보를 요청한 횟수를 나타낸다.


### 목차
1. [개요](#개요)
1. [기능](#기능)
1. [사용법](#사용법)
1. [소스파일](#소스파일)
1. [구조도](#구조도)

## 개요
해당 프로젝트는 `Domain Name`을 `IP Address`로, 또는 그 반대로 변환하는 과정을 수행하는 `DNS Server`구현을 목적으로 한다. 또한 이 `DNS Server`를 사용하는 Local Area Network에서는 IoT 기기들에 명칭을 부여하고 각 기기 간의 통신에 사용할 목적으로 구현한다. 
  
## 기능 
- `Client`의 요청에 따라 특정 `Domain Name` 또는 `IP Address`를 가진 `Host 정보`를 리턴한다.
- `DNS Server`와 `Client`간의 통신에 TCP 프로토콜을 사용한다.
- 내부에 캐시 테이블을 가지고 있다. 만약 `Client`가 요청한 쿼리에 대한 정보가 캐시 테이블에 저장되어있지 않다면 외부 DNS 서버로부터 정보를 얻어온 후 캐시 테이블에 저장한다. 이는 연결된 `DB`에도 저장되며 프로그램 최초 실행 시 DB로부터 메모리로 로드된다.
- 캐시 테이블은 `Hit Count`로 정렬되는 `Priority Queue` 자료구조를 사용하여 Search time을 줄이는 것을 목적으로 하였다. **ㅇㅇ**
- HTTP와 같은 non-persistent connection을 사용하여, `Client`가 `DNS Server`에 쿼리하고 정보를 주고받을 때마다 연결을 생성하고 끊는다.
- `DNS Server` 동작에 대한 Log를 출력하고, 파일로 저장한다. **ㅇㅇ**
-  각 domain에 대한 `Hit Count` 정보를 일별/월별/분기별로 빈도수를 관리한다. **ㅇㅇ**
- *추가 예정*

## 사용법
### 빌드
```
$ cmake CMakeLists.txt
$ make
```
### 실행
```
$ ./dns-server
```

## 소스파일
#### `main.cpp` : 프로그램 시작 루틴
#### `manager.cpp / manager.h` : 매니저
#### `host.cpp / host.h` : Host Entry 클래스 및 Host Entry Builder 클래스
