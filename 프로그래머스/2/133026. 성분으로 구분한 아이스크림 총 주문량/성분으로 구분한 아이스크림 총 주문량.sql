-- 코드를 입력하세요
SELECT
    I.INGREDIENT_TYPE,
    SUM(TOTAL_ORDER) AS TOTAL_ORDER
FROM
    FIRST_HALF F
INNER JOIN  
    ICECREAM_INFO I ON I.FLAVOR=F.FLAVOR
GROUP BY
    I.INGREDIENT_TYPE
ORDER BY
    TOTAL_ORDER ASC
    -- ORDER BY에서는 Alias(TOTAL_ORDER)를 쓰므로 F.를 안 붙여도 됨
    
/*
-두 테이블에 같은 이름의 컬럼이 있을 때 
별칭(I,F) 반드시 붙임. DB가 구분하지 못해 에러 발생 (예: FLAVOR)
-한 테이블에만 있는 컬럼일 때
붙이는 것을 추천. 나중에 같은 이름의 컬럼이 다른 테이블에 생길 경우를 대비 + 가독성*/