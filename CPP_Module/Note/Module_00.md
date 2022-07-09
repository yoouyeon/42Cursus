# 🌟 CPP Module 00

과제를 하면서 공부한 내용들

## 🌸 Namespaces

### 🌱 참고

- [C++ 트레이닝 책 참고](https://www.hanbit.co.kr/store/books/look.php?p_code=B7818919239)

명칭 충돌의 가능성을 피하기 위한 장치. 명칭 작성의 자유가 있고 명칭에 대한 중앙 통제 센터가 없기 때문에 같은 이름을 가진 것들이 발생해도 관리할 수 있는 방법이 없다. 언어 차원에서 이런 명칭 충돌 문제를 해결하기 위해서 네임스페이스라는 개념을 사용하게 되었다.

Namespace : 명칭이 저장되는 영역 (이름을 담는 통)

```cpp
namespace 이름
{
  이 네임스페이스 안에서 사용할 변수나 함수를 선언한다.
}
```

네임스페이스를 별도로 선언하지 않더라도 함수 바깥의 전역 네임스페이스는 항상 존재한다.

네임스페이스에 속한 명칭을 사용할 때에는 `::` 연산자 앞에 그 명칭의 소속 네임스페이스를 밝히면 된다. (`std::string` 이런 식으로)

---

`using namespace` : CPP Module 과제에서는 사용 불가

현재 영역에서 항상 std namespace의 내용을 쓴다고 했을 때 매번 `std::`를 명칭 앞에 붙여주면 가독성이 썩 좋지 않다. 이 때 지정한 네임스페이스의 모든 명칭을 현재 영역으로 가져와 `::` 연산자로 소속을 밝히지 않고도 명칭을 사용할 수 있게 하는 `using` 지시자를 사용할 수 있다.

`using` 지시자는 이 선언이 있는 **영역**에 효력을 발휘한다.

namespace라는 것을 사용하는 이유가 명칭의 소속을 분명히 해서 명칭 충돌을 막기 위해서인데 using 지시자를 사용하게 되면 namespace의 순기능이 흐려지게 된다. → 왠만하면 불편하지 않은 선에서 `using` 지시자를 적당하게 사용해야 하고, 무엇보다 우리 과제에서는 사용하면 안된다.

## 🌸 Class

### 🌱 참고

- [C++ 트레이닝 책 참고](https://www.hanbit.co.kr/store/books/look.php?p_code=B7818919239)

### 🌱 member function

구조체에 포함된 함수를 멤버 함수라고 한다.

C에서 구조체에 함수를 넣고 싶을 때에는 함수 포인터를 넣는 방식으로 구조체에 함수를 포함시킬 수 있었는데 C++에서는 함수 그대로를 구조체의 멤버로 넣을 수 있다.

```cpp
struct Info
{
  char	name[10];
  int	age;
  void selfIntroduce()
  {
    std::cout << "My name is " << name << ". I'm " << age << " years old." << std::endl;
  }
};

int main()
{
  Info penguin = {"pingu", 43};
  penguin.selfIntroduce();
  return (0);
}
```

- 멤버 함수 내에서 같은 소속의 멤버 변수에 접근할 때에는 따로 소속을 명시해 줄 필요가 없다.
- main에서 멤버 함수를 호출할 때에는 멤버 변수에 접근하듯이 `[소속 구조체].[멤버 함수]` 이런 식으로 호출해주면 된다.

```cpp
struct Info
{
  char	name[10];
  int	age;
  void selfIntroduce();
};

void Info::selfIntroduce()
{
	std::cout << "My name is " << name << ". I'm " << age << " years old." << std::endl;
}

int main()
{
  Info penguin = {"pingu", 43};
  penguin.selfIntroduce();
  return (0);
}
```

이렇게 구조체 밖에서 함수를 정의하는 것도 가능하다. 일반 함수 선언과 방식은 동일하지만 함수의 이름 앞에 `::` 연산자를 붙여서 소속 구조체를 밝혀줘야 한다.

- 구조체 내에 함수를 정의하게 되면 인라인 속성을 가지게 된다. 따라서 실제로 함수가 호출되는 것이 아니라 멤버 함수를 호출하는 코드가 함수의 본체 코드와 대체되게 된다. (위의 예제를 예로 들면 `penguin.selfIntroduce();` 이 라인이 `std::cout << "My name is " << name << ". I'm " << age << " years old." << std::endl;` 이렇게 바뀐다는 것) 이렇게 되면 함수의 호출에 대한 부담이 사라져 시간이 빨라지지만 자주 호출하게 되면 실행 파일이 커지게 된다. 따라서 멤버 함수의 코드가 아주 짧을 경우에는 인라인으로 정의하는 것이 유리하다.
- 구조체 외부에 정의하게 되면 일반적인 함수 호출처럼 멤버 함수를 호출한다.
- CPP Module 과제에서는 헤더에 함수를 정의하는 것을 엄격하게 금지하고 있다. (0점사유...)

### 🌱 액세스 지정자

액세스 지정자를 사용해서 구조체 외부에서 구조체 멤버에 접근할 수 있는 권한을 설정할 수 있다.

- `private` : 내부적으로만 사용하는 멤버, 외부에서 읽고 쓰는것이 모두 안된다.
- `public` : 외부에서 자유롭게 사용 할 수 있는 멤버
- `protected` : 자식 클래스만 자유롭게 접근 할 수 있는 멤버

```cpp
struct Info
{
  private:
  	char	name[10];
  	int	age;
  public:
  	void selfIntroduce();
};

void Info::selfIntroduce()
{
 std::cout << "My name is " << name << ". I'm " << age << " years old." << std::endl;
}

int main()
{
  Info penguin = {"pingu", 43};
  penguin.age = 34;	//	에러 발생
  penguin.selfIntroduce();	// public이므로 가능
  return (0);
}
```

private으로 지정한 멤버들에 외부에서 직접적으로 접근하려 하면 에러가 발생한다. 따라서 public에다가 private 멤버 변수들에 접근할 수 있는 함수들을 선언해두는데 이런 함수들을 액세서(Accessor)라고 한다. (get / set 함수들)

### 🌱 class

함수를 포함할 수 있는 C++의 확장된 구조체를 Class라고 한다.

확장된 구조체를 struct 키워드로 선언했을 경우에는 기본 액세스 지정자가 public이지만 class 키워드로 선언했을 경우에는 기본 액세스 지정자가 private이라는 차이점이 있다.

클래스도 타입과 동등한 자격을 가져서 기본 자료형과 거의 동일하게 포인터 연산, 배열 같은 것들을 사용하고 선언 할 수 있다.

### 🌱 인스턴스

아주 간단하게 말하면 어떤 class 타입의 변수. 실제로 메모리에 구현된 그것을 말한다. 객체라고도 한다.

인스턴스의 크기는 클래스 내의 멤버변수 크기의 총합과 같다.

### 🌱 생성자

변수를 생성하듯 클래스의 인스턴스를 생성하면 그 안의 멤버변수들의 값에는 쓰레기값이 들어가기 때문에 당연하게도 그 멤버변수를 초기화하는 작업이 필요할 것이다. 이 선언과 멤버변수 초기화 작업을 동시에 하기 위해서 **생성자**라는 함수를 사용한다.

생성자는 컴파일러가 자동으로 호출하기 때문에 클래스와 이름이 같고 별도의 반환값이 필요하지 않기 때문에 반환형이 없다는 특징이 있다.

생성자 역시 함수이기 때문에 인수를 받아서 그 값으로 멤버변수를 초기화 할 수 있다. 인수 목록을 다르게 해서 다른 방식으로 생성자를 만들 수도 있다! (생성자 오버로딩)

### 🌱 소멸자

생성자로 생성한 인스턴스가 생성되기 전 상태로 돌려놓는 함수가 소멸자. 소멸자의 이름은 `~클래스명` 으로 정해져 있다.

생성자와 소멸자 모두 기본 생성자/소멸자가 있어서 정의하지 않으면 멤버변수를 초기화하지 않는 생성자와 소멸자를 컴파일러가 알아서 만든다.

## 🌸 입출력 스트림

## 🌸 initialization list

### 🌱 참고

- [C++ 트레이닝 책 참고](https://www.hanbit.co.kr/store/books/look.php?p_code=B7818919239)

생성자의 주 역할은 멤버 변수를 초기화하는 것. 그 일을 리스트로 간편하게 할 수 있는 것이 **initialization list** 이다.

```cpp
Account::Account( int initial_deposit ) : _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();
	_totalAmount += initial_deposit;
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created\n";
}
```

이런 식으로 makefile의 defendency 처럼 : 오른쪽에 `멤버변수(초기화할 값)` 형식으로 표시한다.

쓸땐 편하긴 한데 가독성이 좀 떨어진다는 단점은 있다. Body가 시작되기 전에 (그러니까 쓰레기값이 담긴 멤버변수가 생성되기 전에) 멤버변수에 값을 할당하기 때문에 선언과 동시에 초기화하는 것과 비슷하다고 생각하고 있다.

```cpp
std::string str1;
str1 = "C++";

std::string str2 = "kkuljaem";
```

이런 차이? 그렇기 때문에 먼저 쓰레기값을 가지고 나중에 값을 변경할 수 없는, 혹은 애초에 쓰레기값을 값으로 가질 수 없는 멤버변수의 경우에는 이렇게 초기화 리스트를 사용하는 것이 필수적이다.

```cpp
class Some
{
  public:
		const int sangsu;
		int &ref;
}
```

이런 식으로 상수나, 레퍼런스 변수의 경우에는 초기화리스트로 생성과 동시에 멤버변수들을 초기화해줘야 한다. (정확한 동작 원리는 모르겠지만 리스트로 초기화시킬 값을 넘겨주면 `std::string str2 = "kkuljaem";` 이런 식으로 내부적으로 동작하지 않을까? 하는 생각이 든다. (뇌피셜!))

## 🌸 static (정적 멤버)

### 🌱 참고

- [C++ 트레이닝 책 참고](https://www.hanbit.co.kr/store/books/look.php?p_code=B7818919239)

### 🌱 this

객체가 여러 개 있을 때 멤버 변수는 객체별로 따로 갖고 멤버 함수는 여러 객체들이 공유한다.

여러 객체들이 함수를 공유하는 것이기 때문에 함수 내에서 멤버 변수를 접근할 때에는 기본적으로 그 함수를 호출한 객체 자신을 참조하게 된다. 이때 그 함수를 호출한 객체 자신의 포인터가 `this` 인수이다.

멤버 함수 내에서 클래스의 멤버를 참조하는 모든 문장 앞에 `this->`가 암시적으로 적용된다.

암시적으로 적용되는 것이기 때문에 크게 신경쓸 필요는 없지만 함수 내에서 호출한 객체 자신을 칭해야 하는 경우 (다른 객체를 인자로 받는다거나) 혹은 지역변수와 멤버변수의 이름이 충돌할 경우에는 this 인수를 사용해줘야 한다.

### 🌱 정적 멤버 변수

정의 : 클래스에 소속되는 변수이지만 객체별로 할당되지 않고 모든 객체가 공유한다.

필요성? : 객체들이 모두 공유해야 하는 변수가 필요하다고 했을 때 단순히 전역변수로 그 변수를 선언했을 경우에는 객체지향이 지향하는 바와 맞지 않게 된다.

- 클래스와 관련된 정보가 외부에 선언됨 → 캡슐화 위반
- 전역변수는 접근 지정을 할 수 없기 때문에 외부에서 자유롭게 쓰거나 읽을 수 있다. → 정보 은폐가 안됨.

그래서 클래스 안에서 staic 키워드를 붙여서 정적 멤버임을 명시하고, 이 정적 멤버 변수는 클래스 밖에서 :: 키워드로 소속을 밝힌 뒤, 초기화해서 사용한다.

```cpp
// Account.hpp
class Account {
private:
	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;
};

// Account.cpp
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
```

이런 식으로 초기화한다. 그냥 공유 멤버라고 하는 편이 좀 더 이해하기 편할 듯?

이렇게 선언된 정적 멤버 변수는 객체가 생성되기 전에 먼저 생성되고, 객체가 생성될때마다 각 객체의 정적 멤버가 아닌 변수들만 새로 할당된다.

접근 지정도 일반 멤버 변수와 동일하게 할 수 있다. (private, public)

### 🌱 정적 멤버 함수

정적 멤버 함수의 적용 대상은 모든 객체이다. 모든 객체에 공통적인 작업을 처리해야 할 때 정적 멤버 함수를 정의하는 것 같다. ~~(잘 모르겠음..)~~

정적 멤버 함수에는 객체가 전달되지 않는다. (당연함. 적용 대상이 모든 객체이기 때문에?) 그래서 정적 멤버 함수에서는 정적 멤버 변수에만 접근할 수 있다.

그렇기 때문에 생성된 객체가 없더라도 정적 멤버 함수는 호출할 수 있다. (정적 멤버 변수는 최초의 객체 생성 전에도 존재하기 때문에)

정적 멤버 함수는 정적 멤버 변수에 어떤 액션을 취해야 할 때 사용하는 것 같다?!

## 🌸 const (상수 멤버)

### 🌱 참고

- [C++ 트레이닝 책 참고](https://www.hanbit.co.kr/store/books/look.php?p_code=B7818919239)

## 🌸 General rules

### 🌱 참고

- [C++ 트레이닝 책 참고](https://www.hanbit.co.kr/store/books/look.php?p_code=B7818919239)

- <https://en.wikipedia.org/wiki/Pragma_once>
- <https://kldp.org/node/46662>
- <https://caniro.tistory.com/24>

### 🌱 friend

### 🌱 pragma once

### 🌱 Makefile

## 🌸 ex00

### 🌱 참고

### 🌱 std::string

### 🌱 iterator

### 🌱 std::toupper

### 🌱 std::endl

## 🌸 ex01

### 🌱 참고

### 🌱 std::getline

### 🌱 iomanip

#### setfill

#### setw

## 🌸 ex02

### 🌱 참고

### 🌱 iomanip - put_time

### 🌱 오버로딩