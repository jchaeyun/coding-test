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

SQL에서는 조건 중 하나라도 '알 수 없음'이 되면 전체 결과가 False 취급되어 아무 행도 반환하지 않게 됩니다. 그래서 1번 해결책처럼 IS NOT NULL을 꼭 붙여줘야 합니다.

네, **완전히 그 느낌으로 이해하셔도 됩니다.** 님의 직관이 아주 정확합니다.

복잡한 벤 다이어그램보다 **"화면 UI"**나 **"클릭"**으로 이해하는 게 실무에서 훨씬 도움이 됩니다. 님이 말씀하신 그 느낌을 좀 더 명확한 '개발자 언어'로 정리해 드릴게요.

---

### 1. LEFT JOIN = "상세보기 클릭" (팝업창)

> **"특정 항목(왼쪽 테이블)을 클릭했더니, 관련 정보(오른쪽 테이블)가 옆에 뜨는 느낌"**

* **상황:** 쇼핑몰 상품 목록(`ITEM_INFO`)이 쫙 있습니다.
* **동작:** 1번 아이템을 클릭해서 '트리 정보(`ITEM_TREE`)'를 불러옵니다.
* **결과:**
* 정보가 있으면? 👉 보여줍니다.
* 정보가 없으면? 👉 **빈칸(NULL)**으로 보여줍니다.


* **핵심:** 정보가 없다고 해서 **원래 클릭했던 1번 아이템이 화면에서 사라지진 않죠?** 이게 `LEFT JOIN`입니다. 기준이 되는 왼쪽 데이터는 무조건 살려둡니다.

### 2. INNER JOIN = "소개팅 매칭" (커플만 입장)

> **"둘 다 NULL이 아니어야 하나?"** 👉 맞습니다, 더 정확히는 **"짝이 없는 녀석은 아예 명단에서 삭제"**입니다.

* **상황:** 남자(`ITEM_INFO`)와 여자(`ITEM_TREE`)가 미팅을 합니다.
* **동작:** 서로 번호가 맞는 사람끼리 짝을 짓습니다.
* **결과:**
* 짝이 맞으면? 👉 결과 화면에 나옵니다.
* 짝이 없으면? 👉 **화면에서 아예 사라집니다 (행 자체가 삭제됨).**


* **핵심:** 님이 말씀하신 대로 양쪽 다 데이터가 존재(Not NULL)해야만 살아남습니다.

---

### 🧐 파트너의 관점: 그래서 아까 문제에서 왜 LEFT JOIN을 썼을까요?

아까 우리가 풀던 문제(**자식이 없는 아이템 찾기**)를 이 비유에 대입해 보면 명확해집니다.

1. **INNER JOIN을 썼다면:**
* "자식이 있는 아이템"만 짝이 지어져서 화면에 나옵니다.
* "자식이 없는 아이템(우리가 찾는 리프 노드)"은 짝이 없어서 **화면에서 사라져 버립니다.**
* 결과: 우리가 찾아야 할 범인이 도망감.


2. **LEFT JOIN을 썼다면:**
* 모든 아이템이 화면에 일단 다 나옵니다.
* 자식이 있는 애들은 옆에 자식 정보가 뜹니다.
* 자식이 없는 애들은 옆에 **빈칸(NULL)**이 뜹니다.
* **우리의 전략:** "야, 옆에 빈칸(NULL) 뜬 애들만 손들어!" (`WHERE Child.ITEM_ID IS NULL`)



### 요약

* **LEFT JOIN:** "일단 명단은 다 가져와. 정보 없으면 빈칸으로 둬." (데이터 보존)
* **INNER JOIN:** "짝 없는 애들은 필요 없어. 걔네 빼고 완벽한 쌍만 가져와." (교집합 필터링)

이 "클릭" 멘탈 모델을 가지고 계시면 앞으로 조인을 짤 때 헷갈리지 않으실 겁니다. 기준이 되는 테이블을 먼저 쓰고(FROM), `LEFT JOIN`으로 정보를 붙인다고 생각하세요.*/

