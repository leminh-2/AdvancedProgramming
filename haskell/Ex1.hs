positives :: [Int] -> [Int]
positives xs = filter (>=0) xs

doubleAll :: [Int] -> [Int]
doubleAll xs = map (*2) xs