# buloli-interpreter 

![GitHub release](https://img.shields.io/github/release/libera826/buloli-interpreter.svg)
[![CodeFactor](https://www.codefactor.io/repository/github/libera826/buloli-interpreter/badge)](https://www.codefactor.io/repository/github/libera826/buloli-interpreter)
![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)

<img src="https://user-images.githubusercontent.com/24970375/43626716-096b659e-972e-11e8-930d-7e072ee1b76f.jpg" width="20%">

불오리 인터프리터는 BrainFuxx 언어에 영감을 받아 제작되었습니다.

알파벳으로**만** 쓰여진 코드를 작성해 읽어보면 재미있지 않을까? 라는 궁금점에서 출발해 만들게 되었습니다.


# Changelog

모든 변경사항입니다.

## 0.0.2 - 2018-08-XX
### To be added
+ EXTEND Mode (명령어 추가 모드)
  + TTS 명령어
  + 주석 명령어
+ Debug Mode 기능 추가
  + 한 줄씩 실행 기능

## 0.0.1 - 2018-08-10

### Added

+ b, u, l, o, r, i, 총 6가지의 명령어를 지원합니다.

  + b - 포인터 주소 1바이트 증가

    `ptr += 1`

  + u - 포인터 주소 1바이트 감소 

    `ptr -= 1`

  + l - 포인터가 가리키는 값을 1바이트 증가 

    `*ptr += 1`

  + o - 포인터가 가리키는 값을  1바이트 감소 

    `*ptr -= 1`

  + r - 포인터가 가리키는 값을 아스키 문자로 출력 

    `printf("%s", *prt)`

  + i - 포인터가 가리키는 곳에 문자 입력 

    `scanf("%s", &ptr)`
+ Debug Mode를 지원합니다.
