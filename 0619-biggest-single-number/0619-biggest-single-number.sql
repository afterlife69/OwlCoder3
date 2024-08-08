select max(c.x) as num from (select coalesce(max(num),null) as x from mynumbers
group by num having count(num) = 1) c;