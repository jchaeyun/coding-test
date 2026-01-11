-- 코드를 입력하세요
SELECT
    I.NAME AS NAME,
    I.DATETIME AS DATETIME
FROM
    ANIMAL_INS I
LEFT JOIN
    ANIMAL_OUTS O ON I.ANIMAL_ID=O.ANIMAL_ID
WHERE
    O.ANIMAL_ID IS NULL
ORDER BY 
    I.DATETIME ASC
LIMIT 3
/*
**"날짜 순서대로 줄을 세우고(Sort), 위에서 3명만 끊는다(Limit)"**라고 생각하면 됩니다.

SQL 문법으로는 **`ORDER BY`**와 **`LIMIT`**을 사용합니다.
(가장 많이 쓰이는 MySQL 기준입니다.)

### 기본 공식

```sql
SELECT *
FROM 테이블명
ORDER BY 날짜컬럼 ASC  -- 1. 날짜가 '작은(이른)' 순서대로 정렬 (오름차순)
LIMIT 3;              -- 2. 위에서 3개만 가져오기

```

---

### 상세 설명 (엑셀이랑 똑같습니다)

**1. `ORDER BY 날짜컬럼 ASC` (줄 세우기)**

* **ASC (Ascending):** 오름차순. 1 -> 10, 옛날 -> 미래.
* 날짜가 '이르다'는 건 숫자가 작다는 뜻입니다. (2020년 < 2024년)
* 그래서 **제일 예전 날짜**를 보고 싶으면 **ASC**를 씁니다. (생략 가능하지만 써주는 게 명확합니다)


* **DESC (Descending):** 내림차순. 10 -> 1, 미래 -> 옛날.
* **제일 최근 날짜**를 뽑으려면 **DESC**를 씁니다.



**2. `LIMIT 3` (자르기)**

* 정렬된 결과에서 맨 위에서부터 3줄만 보여주고 나머지는 버립니다.

---

### ⚠️ 주의: 사용하는 DB에 따라 문법이 다릅니다

지금 푸시는 문제가 '프로그래머스'나 '해커랭크' 같은 코딩 테스트라면, 선택한 언어(DB)를 확인해보세요.

| DB 종류 | 문법 (상위 3개 뽑기) | 위치 |
| --- | --- | --- |
| **MySQL** (추천) | `LIMIT 3` | 쿼리 맨 끝 |
| **SQL Server** | `TOP 3` | SELECT 바로 뒤 (`SELECT TOP 3 * ...`) |
| **Oracle** | `FETCH FIRST 3 ROWS ONLY` | 쿼리 맨 끝 (최신 버전) |
| **Oracle** (구버전) | `WHERE ROWNUM <= 3` | WHERE 절 (정렬 시 주의 필요) |

**💡 파트너의 팁:**
혹시 코딩 테스트 중이라면 **MySQL**로 설정해서 푸는 게 정신 건강에 좋습니다. Oracle은 `LIMIT` 문법이 버전마다 다르고, 서브쿼리를 써야 정렬이 제대로 먹히는 등 초보자에게 불친절하기 때문입니다.

*/