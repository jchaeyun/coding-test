-- 코드를 작성해주세요
SELECT
    I.ID AS ID,
    N.FISH_NAME AS FISH_NAME,
    I.LENGTH AS LENGTH
FROM
    FISH_INFO I
INNER JOIN
    FISH_NAME_INFO N ON N.FISH_TYPE=I.FISH_TYPE
WHERE
    (I.FISH_TYPE,I.LENGTH) IN
                               (SELECT 
                                    FISH_TYPE,
                                    MAX(LENGTH)
                                FROM
                                    FISH_INFO
                                GROUP BY
                                    FISH_TYPE)
ORDER BY
    I.ID ASC
    
    
/*
해결책: "그룹화"가 아니라 "필터링"으로 접근해야 함
이 문제는 "그룹을 지어 결과를 압축하는 것"이 아니라, "조건(최대 길이)에 맞는 행만 살려두는(Filtering)" 방식으로 접근해야 ID를 살릴 수 있습니다.

방법 A: '다중 컬럼 IN' 사용 (가장 직관적)
서브쿼리를 이용해 (물고기 종류, 그 종류의 최대 길이) 쌍을 먼저 구하고, 내 데이터가 그 쌍(족보)에 포함되는지 확인하는 방식입니다.

SQL

SELECT
    I.ID,
    N.FISH_NAME,
    I.LENGTH
FROM
    FISH_INFO I
INNER JOIN
    FISH_NAME_INFO N ON N.FISH_TYPE = I.FISH_TYPE
WHERE
    -- "내 타입과 길이가, (타입별 최대 길이) 족보에 있는가?"
    (I.FISH_TYPE, I.LENGTH) IN (
        SELECT
            FISH_TYPE,
            MAX(LENGTH)
        FROM
            FISH_INFO
        GROUP BY
            FISH_TYPE
    )
ORDER BY
    I.ID ASC;
💡 설명:

WHERE (A, B) IN (SELECT A, B ...) 문법은 A와 B가 동시에 일치하는 행만 찾아냅니다.

서브쿼리에서 "도미의 최대는 50, 광어의 최대는 30..." 이런 명단을 만듭니다.

메인 쿼리에서 이 명단에 딱 맞는(최대 크기를 가진) 개체만 통과시킵니다.

방법 B: 윈도우 함수 RANK 사용 (앞서 배운 개념 응용)
방금 NTILE을 배우셨으니, 이번엔 순위를 매기는 RANK() 함수를 쓰면 더 세련되게 풀 수 있습니다.

SQL

SELECT
    ID,
    FISH_NAME,
    LENGTH
FROM (
    SELECT
        I.ID,
        N.FISH_NAME,
        I.LENGTH,
        -- 종류(FISH_NAME)별로, 길이(LENGTH)가 큰 순서대로 등수를 매김
        RANK() OVER (PARTITION BY N.FISH_NAME ORDER BY I.LENGTH DESC) AS RNK
    FROM
        FISH_INFO I
    INNER JOIN
        FISH_NAME_INFO N ON N.FISH_TYPE = I.FISH_TYPE
) SUB
WHERE
    RNK = 1 -- 1등만 뽑아냄
ORDER BY
    ID ASC;
이 방식의 장점:

가장 큰 물고기가 여러 마리일 때(공동 1등), 모두 출력됩니다.

GROUP BY의 한계(ID를 선택 못 함)를 완벽하게 우회합니다.

3. Human-AI 파트너의 조언
SQL에서 GROUP BY를 쓸 때의 대원칙을 기억하시면 좋습니다.

"GROUP BY에 참여하지 않은 컬럼(여기선 ID)은 SELECT 절에 그냥 적을 수 없다." (적을 수 있더라도, 엉뚱한 값이 나옵니다.)

따라서 "그룹별 집계 값(최대, 평균 등)"과 "개별 정보(ID, 날짜 등)"를 동시에 보고 싶다면, 무조건 위와 같이 **서브쿼리(WHERE IN)**나 **윈도우 함수(RANK)**를 사용해야 합니다.*/