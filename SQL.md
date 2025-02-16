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

CASE WHEN 조건문 THEN 반환문 : if문과 switch문과 유사함