# SQL 주요 문법 정리

## SELECT
SELECT * FROM [가져올 테이블] : 테이블에 모든 열 가져옴
SELECT 열 이름1 [, 열 이름2] FROM [가져올 테이블] : 테이블에서 열1과 열2를 가져옴

SELECT [가져올 열 정보] FROM [원하는 테이블]
ORDER BY [정렬 기준으로 삼을 열] DESC : 내림차순
ORDER BY [정렬 기준으로 삼을 열] ASC : 오름차순

SELECT [가져올 열 정보]
FROM [원하는 테이블]
WHERE [조건 연산문] : 조건에 맞는 행만 가져옴

SELECT [가져올 열 정보] FROM [원하는 테이블]
LIMIT 2 : 상위 2줄까지만 출력

HAVING 검색조건
GROUP BY {행 이름 | 열 | 위치} 

## SUM, MAX, MIN

SELECT SUM(가져올 열 정보) FROM (원하는 테이블)
GROUP BY 컬럼명;

SELECT MAX(가져올 열 정보) AS (새로 정할 필드 명) FROM (원하는 테이블)
SELECT MIN(가져올 열 정보) FROM (원하는 테이블)
SELECT COUNT(가져올 열 정보) FROM (원하는 테이블)
SELECT COUNT(DISTINCT 가져올 열 정보) FROM (원하는 테이블) : 중복 제거
