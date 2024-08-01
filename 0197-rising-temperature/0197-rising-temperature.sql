select a.id from weather a, weather b where
a.id != b.id and datediff(a.recorddate, b.recorddate) = 1
and b.temperature < a.temperature;