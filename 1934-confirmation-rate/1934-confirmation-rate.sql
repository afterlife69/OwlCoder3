
select x.user_id, round(count(case when x.action = 'confirmed' then 1 end)/count(x.user_id),2) as confirmation_rate from
(select s.user_id, c.action from signups s left join confirmations c
on c.user_id = s.user_id) x group by x.user_id;

# {["user_id", "time_stamp", "user_id", "time_stamp", "action"],
# [[3, "2020-03-21 10:16:13", 3, "2021-07-14 14:00:00", "timeout"], 
#  [3, "2020-03-21 10:16:13", 3, "2021-01-06 03:30:46", "timeout"], 
#  [7, "2020-01-04 13:57:59", 7, "2021-06-14 13:59:27", "confirmed"], 
#  [7, "2020-01-04 13:57:59", 7, "2021-06-13 12:58:28", "confirmed"], 
#  [7, "2020-01-04 13:57:59", 7, "2021-06-12 11:57:29", "confirmed"], 
#  [2, "2020-07-29 23:09:44", 2, "2021-02-28 23:59:59", "timeout"], 
#  [2, "2020-07-29 23:09:44", 2, "2021-01-22 00:00:00", "confirmed"], 
#  [6, "2020-12-09 10:39:37", null, null, null]]}
