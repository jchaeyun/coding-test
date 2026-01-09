-- 코드를 작성해주세요
-- 리프 노드인 아이템을 골라야함(자식이 NULL?)
-- PARENT_ITEM_ID에 안나오는 ITEM_ID인거 고르면 되는거 아님?
SELECT
    I.ITEM_ID AS ITEM_ID,
    I.ITEM_NAME AS ITEM_NAME,
    I.RARITY AS RARITY
FROM
    ITEM_INFO I
JOIN
    ITEM_TREE T ON T.ITEM_ID=I.ITEM_ID
LEFT JOIN
    ITEM_TREE Child ON T.ITEM_ID=Child.PARENT_ITEM_ID 
    -- 나를 부모로 가지는 자식을 알아봄
WHERE
    Child.ITEM_ID IS NULL -- 자식이 없는 경우(NULL)만 남김
ORDER BY
    I.ITEM_ID DESC
    
    /*
    님의 논리("PARENT_ITEM_ID 목록에 내 ID가 없으면 나는 자식이 없는 리프 노드다")는 정확합니다.

하지만 방금 전 대화에서 말씀드린 NOT IN의 함정(NULL 이슈) 때문에 코드가 작동하지 않았을 겁니다. 트리 구조에서 최상위(Root) 노드는 부모가 없으므로 PARENT_ITEM_ID가 NULL인 경우가 반드시 존재하기 때문입니다.

작성하신 코드 흐름을 살려서, 문제를 해결하는 두 가지 수정 버전을 드립니다.

1. 님이 작성한 코드 수정 (NOT IN 사용 시 필수 조치)
서브쿼리 안에서 NULL을 명시적으로 제거해줘야 합니다. 그래야 비교가 정상 작동합니다.

SQL

SELECT
    I.ITEM_ID,
    I.ITEM_NAME,
    I.RARITY
FROM
    ITEM_INFO I
JOIN
    ITEM_TREE T ON I.ITEM_ID = T.ITEM_ID
WHERE
    I.ITEM_ID NOT IN (
        SELECT PARENT_ITEM_ID
        FROM ITEM_TREE
        WHERE PARENT_ITEM_ID IS NOT NULL  -- [핵심] NULL인 부모 ID는 비교 대상에서 제외!
    )
ORDER BY
    I.ITEM_ID DESC; -- (문제 조건에 따라 오름차순/내림차순 확인 필요)
2. 더 안전한 방법 (LEFT JOIN 활용) - 추천
"자식이 없는 아이템"을 찾는 것이므로, 내 ID를 부모로 가지고 있는 행을 찾았을 때 **"없음"**이 나오는 것을 고르는 방식입니다. 이 방식은 NULL 처리를 따로 신경 쓰지 않아도 되어 실수를 줄여줍니다.

SQL

SELECT
    I.ITEM_ID,
    I.ITEM_NAME,
    I.RARITY
FROM
    ITEM_INFO I
JOIN
    ITEM_TREE T ON I.ITEM_ID = T.ITEM_ID
LEFT JOIN
    ITEM_TREE Child ON T.ITEM_ID = Child.PARENT_ITEM_ID -- 나를 부모로 가지는 자식을 찾아봄
WHERE
    Child.ITEM_ID IS NULL -- 자식이 없는 경우(NULL)만 남김
ORDER BY
    I.ITEM_ID DESC;
💡 파트너의 팁: 왜 님의 코드가 멈췄을까요?
님은 "부모 목록에 내 ID가 없으면 돼" 라고 생각하고 다음과 같이 짰습니다.

WHERE ITEM_ID NOT IN (1, 2, NULL)

하지만 SQL은 이걸 이렇게 해석합니다.

ITEM_ID != 1 (참)

ITEM_ID != 2 (참)

ITEM_ID != NULL (알 수 없음 -> UNKNOWN)

SQL에서는 조건 중 하나라도 '알 수 없음'이 되면 전체 결과가 False 취급되어 아무 행도 반환하지 않게 됩니다. 그래서 1번 해결책처럼 IS NOT NULL을 꼭 붙여줘야 합니다.*/