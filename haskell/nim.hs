type Board = [Int]

-- Helper function to check if the board is empty
isEmpty :: Board -> Bool
isEmpty board = all (== 0) board

-- Helper function to remove stars from the board
removeStars :: Int -> Int -> Board -> Board
removeStars row numStars board =
  take row board ++ [max 0 (board !! row - numStars)] ++ drop (row + 1) board

-- Helper function to get user input for row and number of stars to remove
getPlayerMove :: String -> Board -> IO (Int, Int)
getPlayerMove player board = do
  putStrLn $ player ++ " is playing..."
  row <- getRow
  numStars <- getNumStars row
  return (row, numStars)
  where
    getRow = do
      putStrLn "Row?"
      row <- getLine
      case reads row of
        [(rowNum, "")] ->
          if rowNum > 0 && rowNum <= length board && board !! (rowNum - 1) > 0
            then return (rowNum - 1)
            else do
              putStrLn "Invalid row. Please choose a non-empty row."
              getRow
        _ -> do
          putStrLn "Invalid input. Please enter a number."
          getRow
    getNumStars row = do
      putStrLn "How many stars?"
      numStars <- getLine
      case reads numStars of
        [(num, "")] ->
          if num > 0 && num <= board !! row
            then return num
            else do
              putStrLn "Invalid number of stars. Please choose a number between 1 and the number of stars in the row."
              getNumStars row
        _ -> do
          putStrLn "Invalid input. Please enter a number."
          getNumStars row

-- Main game loop
playNim :: Board -> String -> String -> IO ()
playNim board player1 player2 = do
  putStrLn "Initializing..."
  displayBoard board
  play board player1 player2

play :: Board -> String -> String -> IO ()
play board player1 player2 = do
  if isEmpty board
    then putStrLn $ player2 ++ " wins!!!"
    else do
      (row, numStars) <- getPlayerMove player1 board
      let newBoard = removeStars row numStars board
      displayBoard newBoard
      if isEmpty newBoard
        then putStrLn $ player1 ++ " wins!!!"
        else play newBoard player2 player1

-- Helper function to display the board
displayBoard :: Board -> IO ()
displayBoard board = do
  putStrLn "Board:"
  putStrLn $ "1: " ++ stars (board !! 0)
  putStrLn $ "2: " ++ stars (board !! 1)
  putStrLn $ "3: " ++ stars (board !! 2)
  putStrLn $ "4: " ++ stars (board !! 3)
  putStrLn $ "5: " ++ stars (board !! 4)
  where
    stars n = replicate n '*'

-- Start the game
main :: IO ()
main = playNim [5, 4, 3, 2, 1] "Player 1" "Player 2"
