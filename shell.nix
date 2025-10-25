with import <nixpkgs> { };

let
  pythonPackages = python3Packages;
in pkgs.mkShell rec {

  buildInputs = [
    arduino-cli
  ];
}
