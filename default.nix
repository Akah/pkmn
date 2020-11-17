with import <nixpkgs> {}; {
  pkmnEnv = gcc8Stdenv.mkDerivation {
    name = "pkmn-env";
    buildInputs = [
	    pkg-config
	    stdenv
	    gcc
	    SDL2
	    SDL2_image
	    gnumake
	    automake
	    autoconf
	  ];
  };
}

