# c-projects

C projects organized by difficulty level, from junior to senior.

## 📁 Structure

```
c-projects/
├── c-junior/   → junior-level projects
├── c-pleno/    → mid-level projects (coming soon)
└── c-senior/   → advanced projects (coming soon)
```

## 🟢 Junior

| Project | Description | Concepts |
| --- | --- | --- |
| [agenda-contatos](c-junior/agenda-contatos) | Contact book that saves contacts to a file and loads them back on startup | `struct`, arrays, file I/O (`fopen`, `fscanf`, `fprintf`), input validation |
| [jogo-da-velha](c-junior/jogo-da-velha) | Two-player tic-tac-toe in the terminal with win and draw detection | arrays, loops, input validation |
| [jokenpo](c-junior/jokenpo) | Rock, paper, scissors against the computer | `rand`, `srand`, game loop |

## 🛠️ How to compile

```bash
gcc c-junior/jokenpo/jokenpo.c -o jokenpo
./jokenpo
```

Built with GCC (MSYS2 / MinGW) on Windows.

➡️ Fundamentals: [c-basics](https://github.com/renzomelo0906/c-basics)
