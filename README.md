# c-only

## 설치 및 셋업

통상적으로 C컴파일러로 GCC를 사용한다고 한다.

> GCC (GNU Compiler Collection)  
> GNU General Public License (GPL)  

C컴파일러를 윈도우 전역에서 사용하기 위해서는

- `MinGW` 공식사이트에서 직접 설치하는 방법이 있고
- `MSYS2` 라는 윈도우 환경에서 유닉스 유틸을 제공하는 툴을 사용할 수 있다 (본인은 이 방법 사용)

## .GitIgnore

### 포함한 것

- `.c`: 당연히 필요한 핵심 코어

- `.sln`: Solution 파일. Visual Studio에서 여러 프로젝트를 그룹화하고 관리하는 데 사용

- `.vcxproj`: Visual C 프로젝트 파일. 프로젝트에 포함된 파일, 빌드 설정, 컴파일러 옵션 등 프로젝트의 구성 정보를 담고 있음

- `.vcxproj.filters`: Visual Studio 내에서 파일을 필터링하고 정렬하는 데 사용되는 설정을 포함. 예를 들어, 헤더 파일과 소스 파일을 다르게 그룹화하는 등의 구성이 이 파일에 저장.

### 미포함한 것

- `vs/`: Visual Studio의 사용자별 및 머신별 설정을 저장하는 곳. 때때로 권한 문제를 일으킬 수 있음

- `.vcxproj.user`: 사용자별 프로젝트 설정을 저장. 여기에는 디버깅 설정이나 사용자별 선호도 등이 포함.

- `.exe.recipe`: Visual Studio에서 특정 빌드 작업의 결과를 관리하기 위해 사용하는 파일. 빌드 과정에서 생성되는 중간 파일로, 디버깅과 관련된 메타데이터를 포함할 수 있음.

- `.ilk`: Incremental Link File. 빠른 링크를 위해 사용되며, 전체 빌드 대신 변경된 부분만 빌드할 때 사용

- `.idb`: Intermediate Debug File로, 컴파일러가 중간 컴파일 정보를 저장하는 데 사용

- `log`, `tlog`