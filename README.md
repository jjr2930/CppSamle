# CppSamle
콘솔 화면(커맨드라인)으로 플레이하는 똥피하기 게임을 만들어 보았다.

'*': 똥 <br>
P : 플레이어

# 조종방법<br>
a : 왼쪽으로 움직이기<br>
d : 오른쪽으로 움직이기<br>

 <img src="https://github.com/jjr2930/CppSample/blob/main/ReadmeResources/Play.gif?raw=true"/>


# 코드 설명<br>
- 컴포넌트 기반 개발을 사용했다.<br>
(Game Programming Gems 5(정보문화사, 류광 역) "1.3 구성요소 기반 객체 관리"소개된 방법임)
- ObjectManager : 모든 게임오브젝트를 관리한다.
- Entity : Component가 가르킬 소속에 대한 정보
- Conmponent : 무슨 일을 할지에 대한 정의가 있는 부품들의 base class
- game.json : 게임이 어떻게 구성되어 있는지에 대한 설명서

# 클래스 다이어그램 <br>
<img src = "https://github.com/jjr2930/CppSample/blob/main/ReadmeResources/ClassDiagram.png?raw=true"/>
