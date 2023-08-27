euclid :: Int -> Int -> Int
euclid a b
  | b == 0    = a
  | otherwise = euclid b (a `mod` b)

getPositiveInt1 :: IO Int
getPositiveInt1 = do
  input <- getLine
  let n = read input :: Int
  if n > 0
    then return n
    else do
      putStrLn "The number 1 is negative, please input a positive number?"
      getPositiveInt1

getPositiveInt2 :: IO Int
getPositiveInt2 = do
  input <- getLine
  let n = read input :: Int
  if n > 0
    then return n
    else do
      putStrLn "The number 2 is negative, please input a positive number?"
      getPositiveInt2

main :: IO ()
main = do
  putStrLn "Input the number 1?"
  a <- getPositiveInt1
  putStrLn "Input the number 2?"
  b <- getPositiveInt2
  let result = euclid a b
  putStrLn $ "The GCD of 'num1' and 'num2' is " ++ show result
