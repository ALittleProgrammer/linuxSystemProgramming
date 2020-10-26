# vim插件

- 创建.vimrc文件

```shell
cd ~
touch .vimrc
vim .vimrc
```

- 写入一些基础配置

```shell
"去掉vi的一致性"
set nocompatible
"显示行号"
set number
" 隐藏滚动条"    
set guioptions-=r 
set guioptions-=L
set guioptions-=b
"隐藏顶部标签栏"
set showtabline=0
"设置字体"
set guifont=Monaco:h13         
syntax on   "开启语法高亮"
let g:solarized_termcolors=256  "solarized主题设置在终端下的设置"
set background=dark     "设置背景色"
colorscheme solarized
set nowrap  "设置不折行"
set fileformat=unix "设置以unix的格式保存文件"
set cindent     "设置C样式的缩进格式"
set tabstop=4   "设置table长度"
set shiftwidth=4        "同上"
set showmatch   "显示匹配的括号"
set scrolloff=5     "距离顶部和底部5行"
set laststatus=2    "命令行为两行"
set fenc=utf-8      "文件编码"
set backspace=2
set mouse=a     "启用鼠标"
set selection=exclusive
set selectmode=mouse,key
set matchtime=5
set ignorecase      "忽略大小写"
set incsearch
set hlsearch        "高亮搜索项"
set noexpandtab     "不允许扩展table"
set whichwrap+=<,>,h,l
set autoread
set cursorline      "突出显示当前行"
set cursorcolumn        "突出显示当前列"
```

- 安装Vim的插件管理器Vundle

```shell
git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim
```

- 在<b>.vimrc</b>中配置

```shell
filetype off
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

"此处添加所要安装的Vim插件"

call vundle#end()
filetype plugin indent on
```

- 可以添加插件

```shell
Plugin 'VundleVim/Vundle.vim'    "vundle插件"
Plugin 'Valloric/YouCompleteMe'    "自动补全"
Plugin 'nathanaelkane/vim-indent-guides'    "缩进显示"
Plugin 'fholgado/minibufexpl.vim'    "操作多个文件"
Plugin 'Yggdroot/indentLine'    "缩进指示线"
Plugin 'scrooloose/nerdtree'    "树形目录配置"
Plugin 'ctrlpvim/ctrlp.vim'
Plugin 'majutsushi/tagbar'    "显示文件的类、函数、变量"
Plugin 'dyng/ctrlsf.vim'
Plugin 'vim-airline/vim-airline'
Plugin 'vim-airline/vim-airline-themes'
Plugin 'MattesGroeger/vim-bookmarks'
Plugin 'vim-syntastic/syntastic'    "语法检查"
```

