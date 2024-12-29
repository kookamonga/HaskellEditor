# HaskellEditor
This is a simple editor built in Haskell for me to understand functional programming better.

# Compiling it
Install Cabal. I don't know how exactly it is done on Your system, dear reader, but I believe that you might find out by searching "Cabal install (your OS)". 

As for me, given that I use NixOS, I simply added:
`  environment.Packages = with pkgs; [ 
      [rest of my programs, unrelated to haskell]
      cabal-install 
      haskell-language-server
   ]`
And it worked, by miracle or otherwise.
