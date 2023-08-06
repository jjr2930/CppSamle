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
(Game Programming Gems 5(정보문화사, 류광 역) "1.3 구성요소 기반 객체 관리"소개된 방법임)<p>
- 주요 클래스 설명
  - ObjectManager : 모든 게임내에 생서되는 오브젝트를 관리한다.
  - Entity : Component가 가르킬 소속에 대한 정보
  - Conmponent : 무슨 일을 할지에 대한 정의가 있는 부품들의 base class
  - game.json : 게임이 어떻게 구성되어 있는지에 대한 설명서, 이 json의 변경을 통해 게임 구성을 변경할 수 있다.<p>
- 컴포넌트들의 대화 방법(이벤트 프로그래밍)
<img src="https://github.com/jjr2930/CppSample/blob/main/ReadmeResources/%EC%9D%B4%EB%B2%A4%ED%8A%B8%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D.gif?raw=true"/>

# 클래스 다이어그램 <br>
<img src = "https://github.com/jjr2930/CppSample/blob/main/ReadmeResources/ClassDiagram.png?raw=true"/>

# 실행파일 다운로드
<a href = "https://github.com/jjr2930/CppSample/releases/download/v1.0.0/Release.zip"> 클릭하세요 </a>
