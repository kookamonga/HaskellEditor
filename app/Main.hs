{-
  THIS PLACE IS A MESSAGE... AND PART OF A SYSTEM OF MESSAGES... PAY ATTENTION TO IT!
  SENDING THIS MESSAGE WAS IMPORTANT TO ME. I CONSIDER MYSELF A MEDIOCRE PROGRAMMER.
  THIS PLACE IS NOT A PLACE OF HONOR... NO HIGHLY ESTEEMED DEED IS COMMEMORATED HERE... NOTHING VALUED IS HERE.
  WHAT IS HERE IS DANGEROUS AND REPULSIVE TO ME. THIS MESSAGE IS ABOUT A DANGER. 
-}


module Main where

import System.IO

main :: IO ()
main = do
    putStrLn "Welcome to the Shit Haskell Text Editor!"
    putStrLn "Commands: [edit], [save <filename>], [quit]"
    editorLoop ""

-- Editor loop for user commands specified above
editorLoop :: String -> IO ()
editorLoop content = do
    putStr "> "
    hFlush stdout
    command <- getLine
    case words command of
        ["edit"] -> do
            putStrLn "Enter your text (type ':done' on a new line to finish):"
            newContent <- readLines
            editorLoop (content ++ newContent)
        ["save", filename] -> do
            writeFile filename content
            putStrLn $ "File saved as: " ++ filename
            editorLoop content
        ["quit"] -> do
            putStrLn "Exiting editor. Goodbye!"
        _ -> do
            putStrLn "Unknown command. Available commands: [edit], [save <filename>], [quit]"
            editorLoop content

-- Function to read multiple lines until ":done" is entered
readLines :: IO String
readLines = do
    line <- getLine
    if line == ":done"
        then return ""
        else do
            rest <- readLines
            return (line ++ "\n" ++ rest)

