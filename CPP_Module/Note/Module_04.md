# 🌟 CPP Module 04

과제를 하면서 공부한 내용들(을 엄청 대충 정리함)

## 🌸 Subtype polymorphism

02에 Ad-hoc polymorphism 이 언급되었었는데... 흐린 눈으로 넘어갔었다. 이참에 다시보자

### 🌱 polymorphism (다형성)

> 똑같은 호출이라도 상황에 따라, 호출하는 객체에 따라 다른 동작을 할 수 있게 한다. 실제 내부 구현은 다르더라도 개념적으로 동일한 동작을 하는 함수를 하나의 인터페이스로 일관되게 호출할 수 있다. ([C++ 트레이닝](https://hanbit.co.kr/store/books/look.php?p_code=B7818919239) 20p)

`Animal`이라는 클래스에 `makeSound`가 있고, `Animal`이라는 클래스를 상속받은 `Dog`나 `Cat` 클래스가 있다면, 그리고 `makeSound` 함수를 각각의 클래스에 맞게 오버라이딩 해 뒀다면 `Dog`이든 `Cat`이든 상관없이 `makeSound`를 호출해주면 클래스에 맞는 소리가 나온다.

[위키피디아](https://en.wikipedia.org/wiki/Polymorphism_(computer_science))

- 하나의 인터페이스를 가지고 다양한 기능을 구현하거나 (오버라이딩)
- 다양한 타입의 파라미터를 지원하는 동일한 기능의 함수를 만들거나 (오버로딩)

### 🌱 Ad-hoc polymorphism

[위키피디아 - polymorphism (Ad-hoc)](https://en.wikipedia.org/wiki/Polymorphism_(computer_science)#Ad_hoc_polymorphism)

[위키피디아 - Ad-hoc polymorphism (안읽어봄)](https://en.wikipedia.org/wiki/Ad_hoc_polymorphism)

> polymorphic functions that can be applied to arguments of different types, but that behave differently depending on the type of the argument to which they are applied
> 
> 다른 자료형의 인자를 받았을 때, 그 타입에 맞는 작업을 할 수 있는 함수.


`+` 연산자를 예로 들면, `int + int` 는 `int`의 결과가 나오고, `string + string`은 앞 `string`에 뒤 `string`을 append 한 결과가 나온다. 이런 타입의 다형성을 애드혹 다형성... 이라고 하는 것 같다.

### 🌱 Subtype polymorphism

[위키피디아 - polymorphism (Subtyping)](https://en.wikipedia.org/wiki/Polymorphism_(computer_science)#Subtyping)

[위키피디아 - Subtyping (안읽어봄)](https://en.wikipedia.org/wiki/Subtyping)

아까 위에서 Animal과 makeSound 함수로 예를 들었던 다형성이 Subtype polymorphism이다. 같은 부모 클래스를 상속받은 형제 클래스에서 (형제 클래스라는 명칭이 바른 말인지는 모르겠다.) 같은 부모클래스의 함수를 오버라이딩 했을 때, 나중에 Animal이라는 객체 포인터에 담아서 일괄적으로 같은 함수를 호출했을 때, 각각의 자식클래스에 맞는 함수들이 호출되는 것을 의미하는 것 같다. (CPP 04에서 계속 하게 되는 것이다.)

구구절절 적었는데 사실 코드를 보는 편이 더 이해가 잘 되는 것 같다. (출처 : [위키피디아 - polymorphism (Subtyping)](https://en.wikipedia.org/wiki/Polymorphism_(computer_science)#Subtyping))

```cpp
abstract class Animal {
    abstract String talk();
}

class Cat extends Animal {
    String talk() {
        return "Meow!";
    }
}

class Dog extends Animal {
    String talk() {
        return "Woof!";
    }
}

static void letsHear(final Animal a) {
    println(a.talk());
}

static void main(String[] args) {
    letsHear(new Cat());
    letsHear(new Dog());
}
```

`letsHear` 함수에서는 `Animal` 객체를 받아와서 `talk` 함수를 호출한다. 만약 Subtype polymorphism이 잘 구현되어 있다면, `letsHear(new Cat())`로 `Cat` 객체를 `letsHear` 함수에 전달하면 "Meow!" 가 출력이 될 것이고, `letsHear(new Dog())`로 `Dog` 객체를 `letsHear` 함수에 전달하면 "Woof!" 가 출력이 될 것이다.

이런 동작이 가능하게 하기 위해서는 동적 바인딩 (late binding)이 가능하게 해야 하고, C++에서는 가상함수 테이블을 이용해서 동적 바인딩을 하게 한다. 관련 내용은 CPP 03에서 공부했었다. ([CPP Module 03 note - virtual 참고](https://github.com/yoouyeon/42Cursus/blob/main/CPP_Module/Note/Module_03.md#-virtual))
