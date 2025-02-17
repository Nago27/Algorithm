# SQL 주요 문법 정리 (프로그래머스)

## SELECT
SELECT * FROM [가져올 테이블] : 테이블에 모든 열 가져옴
SELECT 열 이름1 [, 열 이름2] FROM [가져올 테이블] : 테이블에서 열1과 열2를 가져옴

SELECT [가져올 열 정보] FROM [원하는 테이블]
ORDER BY [정렬 기준으로 삼을 열] DESC : 내림차순
ORDER BY [정렬 기준으로 삼을 열] ASC : 오름차순

SELECT [가져올 열 정보] FROM [원하는 테이블]
WHERE [조건 연산문] : 조건에 맞는 행만 가져옴
+ IS NULL : 특정 칼럼의 데이터가 NULL인 테이블을 가져옴
LIKE ' ' : 단어에 특정 문자열이 포함되어 있는지 확인하는 방법 (%와 함께 사용)

SELECT [가져올 열 정보] FROM [원하는 테이블]
LIMIT 2 : 상위 2줄까지만 출력

GROUP BY {행 이름 | 열 | 위치} 

- SQL 동작순서
FROM - ON - JOIN - WHERE - GROUP BY - HAVING - SELECT - DISTINCT - ORDER BY

## SUM, MAX, MIN

SELECT SUM(가져올 열 정보) FROM (원하는 테이블)
GROUP BY 컬럼명;

SELECT MAX(가져올 열 정보) AS (새로 정할 필드 명) FROM (원하는 테이블)
SELECT MIN(가져올 열 정보) FROM (원하는 테이블)
SELECT COUNT(가져올 열 정보) FROM (원하는 테이블)
SELECT COUNT(DISTINCT 가져올 열 정보) FROM (원하는 테이블) : 중복 제거

## GROUP BY
: 특성 속성을 기준으로 그룹화 하여 검색할때 그룹화 할 속성을 지정
HAVING : 그룹화 이후 데이터들에 대해 조건을 줌

AS ~ : 칼럼 명 바꿀때 사용 / ex. FROM ICECREAM_INFO AS I -> 테이블 명을 I로 바꿈 (참조시 I.[칼럼명])
ORDER BY (정렬대상[ASC/DESC]) : 결과 값을 정렬
AVG : 평균값 산출 -> 반드시 그룹화를 사용해야 함
TRUNCATE(버림할 숫자, 숫자의 소수점 이하 자릿수) 
BETWEEN 숫자 and 숫자 : 사이값 조건

YEAR(), MONTH(), HOUR() .. : 날짜/시간 변환

DATE_FORMAT(컬럼명,'%Y-%m-%d') : 데이터 포멧 변경

CASE WHEN 조건문 THEN 반환문 : if문과 switch문과 유사함

## JOIN 
: 서로 다른 테이블을 합쳐서 하나의 테이블로 형성

SELECT 컬럼명 
FROM 테이블1 AS A 
	< INNER | LEFT | RIGHT | FULL > JOIN 테이블2 AS B 
	-- 👆🏻 가독성을 위해 보통 테이블 명은 alias를 사용해 간단하게 표현해 사용합니다.
	ON A.foreign_key = B.id_key
	-- 👆🏻 조인 조건으로 A테이블의 외래키를 B테이블이 id_key라는 컬럼명으로 참조하고 있을 때,
	-- ON 으로 외래키와 참조키를 설정해주면, 두 컬럼을 비교해서 같은 값끼리 하나의 row로 나타내줍니다.
[WHERE 조건식]
[GROUP BY 컬럼명 혹은 표현식]
[HAVING 조건식]
[ORDER BY 컬럼명]	

* SELECT로 조회할 컬럼명이 테이블1과 테이블2에 모두 있는 겹치는 이름이라면 점표기법을 사용해 [테이블명.컬럼명]으로 명시
 ROUND(컬럼명, (반올림할 자리수))
* &(and), |(or) 연산자로 2진수 비트 판별 가능

INNER JOIN : 각 테이블에서 조인 조건으로 사용된 컬럼에 값이 둘 다 존재한 경우, 지정 조건을 만족한 컬럼만 합침 (교집합)
OUTER JOIN : (LEFT: 테이블1을 기준으로 합침 | RIGHT: 테이블2를 기준으로 합침 | FULL: LEFT,RIGHT 결과를 합침) (합집합)

USING : 두 테이블에서 조인 조건으로 사용되는 컬럼들의 이름이 같을때, 컬럼명만으로도 join 가능
UNION 
- 서로 다른 종류의 테이블도 조회하는 컬럼을 일치시키면 집합 연산이 가능
- 총 컬럼의 수와 각 컬럼의 데이터 타입만 일치하면 UNION 연산
- UNION을 사용했을 때 중복을 제거하면서 우연히 같은 값이라 누락되는 값이 있을 수 있음
  -> UNION ALL 연산자를 사용하면 합집합을 보여주면서 중복을 제거하지 않고 겹치는 값을 모두 볼 수 있음
