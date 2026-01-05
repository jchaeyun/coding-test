-- 코드를 입력하세요
SELECT
    CAR_ID,
    CASE
    WHEN MAX('2022-10-16' BETWEEN START_DATE AND END_DATE)=1 THEN '대여중'
    -- 조건에 맞는게 하나라도 있으면 TRUE(1) 반환
    ELSE '대여 가능'
    END AS AVAILABILITY
FROM 
    CAR_RENTAL_COMPANY_RENTAL_HISTORY
GROUP BY
    CAR_ID
ORDER BY
    CAR_ID DESC
/*
코드 해석 (파트너의 팁)
'2022-10-16' BETWEEN START_DATE AND END_DATE:

날짜가 대여 기간 사이에 껴있으면 1(True), 아니면 0(False)을 반환합니다.

MAX(...):

한 자동차의 여러 기록 중 1(대여중)이 단 하나라도 있으면, 최댓값은 1이 됩니다.
->2 이상 나올 일은 없음. 같은 CAR_ID면 같은 날짜에는 한번만 대여되니까
모두 0(대여 안 함)이어야 최댓값이 0이 됩니다.

CASE WHEN ... = 1:

최댓값이 1이면(즉, 겹치는 날짜가 하나라도 있으면) '대여중'으로 표시합니다.
*/