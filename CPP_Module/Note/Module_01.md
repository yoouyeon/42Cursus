# 🌟 CPP Module 01

과제를 하면서 공부한 내용들

## 🌸 Memory allocation

```cpp
int i = 7;
```

위 방식으로 할당된 변수의 메모리는 스택에 저장된다. 이렇게 생성된 **자동변수**는 실행 흐름이 선언된 스코프를 벗어나면 할당되었던 메모리가 자동으로 회수된다.

```cpp
int *ptr = new int
```

C++에서는 new 키워드로 메모리를 동적할당할 수 있다. 이 때 할당된 메모리는 힙 영역에 저장된다.

- 메모리 동적 할당 → `new` 키워드
- 동적할당된 메모리 해제 → `delete` 키워드

---

기존에 C에서 메모리 동적할당시에 사용했던 malloc 함수도 C++에서 지원하긴 하지만 new, delete 키워드를 더 권장하는 이유는 객체를 동적할당할 때 생성자까지 호출해주기 때문이다.

- `malloc` : 단순히 주어진 크기의 메모리만 할당. 객체에 관련된 동작은 하지 않는다.
- `new` : 메모리를 할당하고, 생성자를 호출하여 객체를 생성한다.
- `free` : 단순 메모리 해제
- `delete` : 소멸자를 호출해서 동적으로 생성된 객체를 정상적으로 제거한다.

---

메모리 할당에 실패하는 경우에는 기본적으로는 프로그램이 종료된다. `new`의 버전에 따라서는 `nullptr`를 리턴하기도 한다고 함.

---

배열을 heap 공간에 동적으로 할당하기.

```cpp
int *myArray ptr = new int[5];

delete ptr;
```

`new` 로 할당한 메모리 공간은 delete로 해제하고, `new[]` 로 할당한 메모리 공간은 `delete[]` 로 한번에 제거한다.

### 🌱 참고

- [전문가를 위한 C++](https://www.hanbit.co.kr/media/books/book_view.html?p_code=B3215427289)

## 🌸 references

레퍼런스란 일종의 변수에 대한 alias이다. 레퍼런스를 이용해서 수정한 내용은 그 레퍼런스가 가리키는 변수에 그대로 반영이 된다. (심볼릭 링크와 비슷한 느낌인 것 같다.) 책에서는 변수의 주소를 가져오거나 변수에 대한 역참조 연산을 수행하는 작업을 자동으로 처리하는 특수한 포인터라고 한다.

변수, 클래스의 멤버를 레퍼런스로 만들 수 있고, 함수나 멤버함수가 레퍼런스를 매개변수로 받거나, 레퍼런스를 리턴할수도 있다.

레퍼런스는 어쨌든 또 다른 이름이므로 코드가 저장되는 코드 영역에 저장될 수도 있는데, 경우에 따라서는 스택 영역에 저장되기도 한다. (평가받으면서 들은 지식 추가함)

### 🌱 레퍼런스 변수

레퍼런스 변수는 반드시 생성하자마자 초기화해야 한다. 만약에 레퍼런스 변수를 클래스 안에서는 선언만 하고, 초기화는 밖에서 한다면 컴파일 에러가 발생한다.

레퍼런스는 처음 초기화 할 때 지정한 변수만 가리킨다. 즉 **한번 생성되고 나면 가리키는 값을 바꿀 수 없다.** 만약에 레퍼런스 대상을 바꾸기 위해서 어떤 값을 다시 대입하면, 그 레퍼런스의 대상이 바뀌는 것이 아니라 레퍼런스가 가리키는 대상의 값이 바뀌게 되는 것이다.

클래스의 멤버를 레퍼런스로 선언하게 된다면, 선언과 동시에 초기화되어야 하므로 반드시 생성자의 본문이 아니라 생성자 이니셜라이저에서 초기화해야 한다. ([initialization list](https://github.com/yoouyeon/42Cursus/blob/main/CPP_Module/Note/Module_00.md#-initialization-list))

### 🌱 레퍼런스 매개변수

기본적으로 함수 매개변수는 call by value로 처리해서 매개변수로 받은 값은 인수의 복사본을 받게 된다. 하지만 매개변수를 레퍼런스 타입으로 선언하면 call by reference 로 처리해서 원본 인수의 값도 바꿔줄 수 있다. (마치 포인터를 전달하는 것처럼!)

### 🌱 레퍼런스 필요성?

레퍼런스로 할 수 있는 일을 모두 포인터로 처리할 수 있는데? 왜 또 필요하지? (라고 매번 평가다닐때마다 여쭤봤음ㅎㅎ)

레퍼런스를 사용하면 코드를 더 깔끔하고 읽기 쉽게 작성할 수 있다. 그리고 레퍼런스의 값은 절대 NULL이 될 수 없기 때문에 NULL에 접근할 위험성이 적어진다.

하지만 배열을 동적으로 할당하는 경우 / 주소를 바꿔야 하는 경우에는 레퍼런스를 사용하는 것이 좋지 않거나, 사용이 불가능하다.

- 포인터 : 메모리 소유권을 이어받아 / 넘겨받아 메모리를 해제해야 할 일이 있는 경우 → 포인터 타입의 매개변수 / 리턴값
- 레퍼런스 : 메모리 소유권을 넘길 일이 없는 경우 → 레퍼런스 타입의 매개변수 / 리턴값

### 🌱 참고

- [전문가를 위한 C++](https://www.hanbit.co.kr/media/books/book_view.html?p_code=B3215427289)

## 🌸 switch statement

조건으로 지정한 표현식의 결과에 따라 수행한 동작을 선택한다. 표현식은 결과가 반드시 정수타입, 정수 타입으로 변환할 수 있는 타입, 열거타입, 상수와 비교가능한 타입이어야 한다. (어쨌든 정수)

조건에 맞는 상수값을 case 문으로 지정한 뒤에, 조건에 맞는 경우에는 case 문 아래에 나오는 코드를 실행하고 break 가 나오면 종료한다. 만약에 이후의 case까지 모두 실행하고 싶은 경우에는 break를 걸어주지 않으면 된다! (이렇게 실행되는 것을 fallthrough라 부른다.) default 키워드를 넣어주면 앞선 모든 케이스와 일치하지 않는 경우의 동작을 지정해 줄 수 있다.

## 🌸 file stream

C++ 은 파일 입출력을 위해서 `std::ofstream`과 `std::ifstream` 클래스를 지원하고, 둘 다 `<fstream>` 헤더파일에 정의되어 있다. 파일 입출력 중 발생할 수 있는 에러상황의 경우에는 표준입출력 스트림에서와 동일하게 `good()`, `eof()`, `bad()`, `fail()` 함수를 이용해서 에러처리 해 주면 된다.

파일 스트림 생성자는 파일의 이름과 파일을 열 때 적용할 모드에 대한 인수를 받는다. C에서의 open 함수와 동일하게 모드들은 | 연산자로 조합해서 지정할수도 있다.

- `ios_base::app` : 파일을 열고 쓰기 연산을 수행하기 전에 파일 끝으로 간다.
- `ios_base::ate` : 파일을 열고 즉시 파일 끝으로 간다.
- `ios_base::binary` : 입출력을 기존 텍스트 모드에서 바이너리 모드로 실행한다.
- `ios_base::in` : 입력할 파일을 열고 시작 지점부터 읽는다. (`ifstream` 기본 모드)
- `ios_base::out` : 출력할 파일을 열고 시작 지점부터 쓴다. 기존 데이터가 있다면 덮어쓴다. (`ofstream` 기본 모드)
- `ios_base::trunc` : 출력할 파일을 열고 기존 데이터를 모두 삭제한다.

`ifstream` 과 `ofstream` 소멸자는 자동으로 열었던 파일을 닫기 때문에 `close()` 함수를 직접적으로 호출하지 않아도 된다.

### 🌱 참고

- [전문가를 위한 C++](https://www.hanbit.co.kr/media/books/book_view.html?p_code=B3215427289)

## 🌸 String method

[String Class](https://github.com/yoouyeon/42Cursus/blob/main/CPP_Module/Note/Module_00.md#-stdstring)

### 🌱 문자열 연산

string은 클래스이지만 string 헤더파일을 인클루드하면 연산자들이 오버로딩되어 있기 때문에 마치 기본타입처럼 사용할 수 있다.

```cpp
// + 연산 (연결(결합))
{
	std::string A = "test";
	std::string B = ".replace";
	std::string C = A + B;	// C는 "test.replace" 이다.
}

// += 연산 (append)
{
	std::string A = "test";
	std::string B = ".replace";
	A += B;	// A는 "test.replace" 이다.
}

// 비교 연산자 (일치, 사전식 나열 순서에 따른 비교)
{
	std::string A = "ab";
	std::string B = "cd";
	std::string C = "ab";
	if (A == B)
		std::cout << "A == B" << std::endl;
	else if (A > B)
		std::cout << "A > B" << std::endl;
	else
		std::cout << "A < B" << std::endl;
	if (A == C)
		std::cout << "A == B" << std::endl;
	else if (A > C)
		std::cout << "A > C" << std::endl;
	else
		std::cout << "A < C" << std::endl;
}
```

스트링을 할당하거나 크기를 조절하는 코드가 흩어져있어도 string 객체는 모두 스택 공간에 생성되기 때문에 scope를 벗어나는 즉시 할당된 메모리를 string 소멸자가 정리하기 때문에 메모리 누수 문제가 발생할 가능성이 적다. (string 내부에서는 계속해서 동적할당/해제가 반복되고 있기 때문에 string 내용을 저장하는 메모리는 힙에 할당이 되는 것 같다.)

### 🌱 find

```cpp
size_t find (const string& str, size_t pos = 0) const;
size_t find (const char* s, size_t pos = 0) const;
size_t find (char c, size_t pos = 0) const;
```

문자열에서 문자열(char 배열 / 문자)를 찾아서 첫번째로 매칭되는 부분의 위치를 반환한다. 만약에 없으면 `std::npos`라는 상수를 반환한다. (cpluscplus 사이트에는 -1로 정의되어있다고 하는데 클러스터맥에선 좀 다른 것 같기도 하다. 아무튼 상수.)

첫번째 인자는 호출한 string에서 찾고자 하는 문자열(char 배열 / 문자)이고 두번째 인자는 search를 시작할 문자열 상에서의 위치이다. 기본값은 0이고 만약에 string.length() 보다 pos가 크면 찾지 못하고 std::npos를 반환하는 것 같다.

```cpp
int main(void)
{
	std::string A = "aaabbbcccdddeeecccfff";
	std::string B = "ccc";
	std::cout << A.find(B) << std::endl;
	std::cout << A.find("ccc") << std::endl;
	std::cout << A.find(B, 10) << std::endl;
	std::cout << A.find(B, 40) << std::endl;
	std::cout << A.find('z') << std::endl;
	return (0);
}
```

![string_find_test](./imgs/string_find_test.png)

### 🌱 erase

```cpp
string& erase (size_t pos = 0, size_t len = npos);
```

호출한 string에서 `pos`지점부터 `len` 만큼의 문자를 지운다. 이렇게 지운 뒤에 길이 또한 조정해준다. 기본값은 `pos = 0`,`len = npos`이므로 문자열의 시작부터 끝.

```cpp
int main(void)
{
	std::string A = "aaabbbcccdddeee";
	std::cout << A << std::endl;
	std::cout << A.length() << std::endl;
	int idx = A.find("bbb");
	A.erase(idx, 3);
	std::cout << A << std::endl;
	std::cout << A.length() << std::endl;
	A.erase();
	std::cout << A << std::endl;
	std::cout << A.length() << std::endl;
	return (0);
}
```

![string_erase_test](./imgs/string_erase_test.png)

### 🌱 insert

```cpp
string& insert (size_t pos, const string& str);
```

`pos` 위치 **앞**에 `str`을 삽입한다.(새로 삽입되는 문자열의 첫번째 문자 위치가 `pos`가 되는 것) 만약에 pos가 호출한 string의 length 보다 큰 경우에는 out_of_range 에러를 던진다.

```cpp
int main(void)
{
	std::string A = "aaabbbcccdddeee";
	std::cout << A << std::endl;
	std::cout << A.length() << std::endl;
	int idx = A.find("bbb");
	A.insert(idx, "zzz");
	std::cout << A << std::endl;
	std::cout << A.length() << std::endl;
	return (0);
}
```

![string_insert_test](./imgs/string_insert_test.png)

### 🌱 참고

- [전문가를 위한 C++](https://www.hanbit.co.kr/media/books/book_view.html?p_code=B3215427289)
- [C++ 트레이닝](https://www.hanbit.co.kr/store/books/look.php?p_code=B7818919239)
- <https://cplusplus.com/reference/string/string/find/>
- <https://cplusplus.com/reference/string/string/insert/>
- <https://cplusplus.com/reference/string/string/erase/>
- <https://cplusplus.com/reference/string/string/npos/>
