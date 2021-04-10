아직 입양을 못 간 동물 중, 가장 오래 보호소에 있었던 동물 3마리의 이름과 보호 시작일 조회

- JOIN 사용
```sql
SELECT *
FROM(
    SELECT i.name, i.datetime
    FROM animal_ins i left join animal_outs o
    ON i.animal_id=o.animal_id
    WHERE o.animal_id is null
    ORDER BY datetime)
WHERE rownum<=3;
```

- 서브쿼리 사용
```sql
select name, datetime
from (select *
    from animal_ins 
    where animal_id not in (
        select animal_id
        from animal_outs
    )
    order by datetime)
where rownum<=3;
```
