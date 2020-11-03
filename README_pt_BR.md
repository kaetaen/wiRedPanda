# WiRed Panda

[![Build Status](https://travis-ci.org/GIBIS-UNIFESP/wiRedPanda.svg?branch=master)](https://travis-ci.org/GIBIS-UNIFESP/wiRedPanda)

WiRed Panda é um software gratuito desenvolvido para ajudar os alunos a aprender sobre circuitos lógicos e simulá-los de forma fácil e amigável.

Suas principais características são:
  - Funcionar em Windows, macOS e Linux;
  - Permite a simulação em tempo real de circuitos lógicos;
  - Interface amigável;
  - Intuitivo e fácil de se usar;
  - Exporta para imagens ou PDF.

Read me in [English](README.md).
   
![Tela principal](https://user-images.githubusercontent.com/36349314/97934063-532ed000-1d53-11eb-9667-73ea32f456ce.png)

## Downloads

Binário compilados para Windows e Linux podem ser encontrados [aqui](http://gibis-unifesp.github.io/wiRedPanda/downloads/).
Binários _linkados_ dinâmicamente para Linux e macOS podem ser encontrados [aqui](https://github.com/GIBIS-UNIFESP/wiRedPanda/releases).

## Compilação

### Em Linux & macOS

#### Dependências

* Distros baseadas em Debian Buster 10+ ou Ubuntu 18.04+.

```bash
sudo apt install qt5-default qt5-qmake qtmultimedia5-dev libqt5charts5-dev
```

* Debian Stretch 8+ or Ubuntu 16.04+ based distros

Algumas das dependências necessárias não estão nos repositórios padrão.

```bash
sudo add-apt-repository ppa:beineri/opt-qt-5.10.1-trusty
sudo apt update 
sudo apt install dh-make qt510base qt510charts-no-lgpl qt510multimedia
```

* Fedora

```bash
sudo dnf install qt5 qt5-devel qt5-qtmultimedia-devel qt5-charts-devel
```

* macOS

Você pode ou [compilar o Qt5](https://doc.qt.io/qt-5/macos-building.html) ou baixá-lo através do [Homebrew](https://brew.sh/).


```bash
brew install qt
```

#### Processo de compilação

```bash
git clone https://github.com/GIBIS-UNIFESP/wiredpanda.git
mkdir wiredpanda/build
cd wiredpanda/build
qmake ../WPanda.pro
make -j$(nproc)
```

Note: este processo pode demorar vários minutos para ser concluído. Uma vez terminado, o executável se encontrará em `wiredpanda/build/app/wpanda`, quando usando Linux, e em `wiredpanda/build/app/wpanda.app/Contents/MacOS/wpanda` quando em macOS.


## Licensing

O WiRed Panda este software é licenciado sob a [Licença Pública Geral GNU, Versão 3.0](http://www.gnu.org/licenses/).

Veja o arquivo [`LICENSE`](LICENSE) para o texto completo da licença.
  
    Copyright (C) 2020 - Davi Morales, Fábio Cappabianco, Lucas Lellis, Rodrigo Torres e Vinícius Miguel.

    Este programa é um software livre: você pode redistribuí-lo e / ou modificar
    sob os termos da Licença Pública Geral GNU conforme publicada pela Free Software Foundation, seja a versão 3 da Licença, ou
    (à sua escolha) qualquer versão posterior.
    
    Este programa é distribuído na esperança de que seja útil,
    mas SEM QUALQUER GARANTIA; sem mesmo a garantia implícita de COMERCIABILIDADE ou ADEQUAÇÃO A UM DETERMINADO FIM. Veja a GNU General Public License para mais detalhes.

    Você deve ter recebido uma cópia da Licença Pública Geral GNU
    junto com este programa. Caso contrário, consulte <http://www.gnu.org/licenses/>.