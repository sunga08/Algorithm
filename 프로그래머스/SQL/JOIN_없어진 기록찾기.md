입양을 간 기록은 있는데, 보호소에 들어온 기록이 없는 동물의 ID와 이름을 ID 순으로 조회

- JOIN 사용 : JOIN 후 INS 테이블의 animal_id가 null인 데이터 찾기
```sql
SELECT o.animal_id, o.name
from animal_outs o left join animal_ins i
where o.animal_id=i.animal_id
and i.animal_id is null
order by animal_id;
```

- 서브쿼리, NOT IN 사용
```sql
SELECT animal_id, name
FROM animal_outs
WHERE animal_id not in(
    SELECT animal_id FROM animal_ins
)
ORDER BY animal_id;
```
