from pathlib import Path
from uuid import uuid4
from datetime import date
import re, shutil, zipfile, json
from PIL import Image
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
from matplotlib.patches import FancyBboxPatch, FancyArrowPatch, Rectangle, Circle
from matplotlib.font_manager import FontProperties

BASE=Path('/mnt/data')
WORK=BASE/'working_predicate43'
OUT=WORK/'bundle'
OUT.mkdir(exist_ok=True)
orig=BASE/'谓词逻辑推理_完整笔记/第7讲_谓词逻辑推理_完整整理.md'
assets=f'DiscreteMath_20261110_PredicateLogicInference_{uuid4().hex[:16]}_assets'
root=OUT/assets
img_dir=root/'images'
source_dir=root/'source'
img_dir.mkdir(parents=True,exist_ok=True)
source_dir.mkdir(parents=True,exist_ok=True)
labels={
 'implication':'logic_implication_graph',
 'capture':'logic_variable_capture',
 'matrix':'logic_quantifier_order_counterexample',
 'witness':'logic_distinct_witnesses',
 'proof':'logic_proof_ei_ui_eg',
 'distribution':'logic_distribution_counterexample',
}
name_map={k:f'{v}_{uuid4()}' for k,v in labels.items()}
map_file=WORK/'name_map.json'
map_file.write_text(json.dumps({'folder':assets,'files':name_map},ensure_ascii=False,indent=2),encoding='utf-8')

FONT='/usr/share/fonts/opentype/noto/NotoSansCJK-Regular.ttc'
font=FontProperties(fname=FONT)
blue='#215c94';ink='#172b44';teal='#158069';orange='#b05b35';red='#b54745';gray='#5b6e80';soft='#f1f6fb';line='#a4bcd2';greenbg='#e1f3ec';redbg='#fae9e5'
plt.rcParams.update({'mathtext.fontset':'stix','axes.unicode_minus':False,'svg.fonttype':'path','savefig.facecolor':'white','figure.facecolor':'white'})

def t(ax,x,y,s,size=18,color=ink,ha='center',va='center',math=False,**kwargs):
 p={'fontsize':size,'color':color,'ha':ha,'va':va,'clip_on':False,**kwargs}
 if not math:p['fontproperties']=font
 return ax.text(x,y,s,**p)

def b(ax,x,y,w,h,s,math=True,fc=soft,fontsize=22):
 ax.add_patch(FancyBboxPatch((x-w/2,y-h/2),w,h,boxstyle='round,pad=0.03,rounding_size=.12',edgecolor=line,linewidth=1.8,facecolor=fc))
 t(ax,x,y,s,fontsize,math=math)

def arr(ax,p1,p2,c=blue,ms=22,lw=2.6,rad=0):
 ax.add_patch(FancyArrowPatch(p1,p2,arrowstyle='-|>',mutation_scale=ms,linewidth=lw,color=c,connectionstyle=f'arc3,rad={rad}',shrinkA=2,shrinkB=2))

def save(fig,key):
 filename=name_map[key]
 p=img_dir/(filename+'.png')
 fig.savefig(p,dpi=230,bbox_inches='tight',pad_inches=.24,facecolor='white')
 fig.savefig(source_dir/(filename+'.svg'),bbox_inches='tight',pad_inches=.24,facecolor='white')
 plt.close(fig)
 return p

# 1: implication DAG; each arrow is valid for nonempty domains.
fig,ax=plt.subplots(figsize=(12,7))
ax.set(xlim=(0,12),ylim=(0,7.5));ax.axis('off')
t(ax,6,7.12,'二元量词公式：单向推出关系',25)
t(ax,6,6.57,'箭头方向表示“前式可以推出后式”，不是双向等值',16,color=gray)
b(ax,6,5.7,4.1,.78,r'$\forall x\,\forall y\,P(x,y)$')
b(ax,3,4.2,4.1,.78,r'$\exists y\,\forall x\,P(x,y)$')
b(ax,9,4.2,4.1,.78,r'$\exists x\,\forall y\,P(x,y)$')
b(ax,3,2.6,4.1,.78,r'$\forall x\,\exists y\,P(x,y)$')
b(ax,9,2.6,4.1,.78,r'$\forall y\,\exists x\,P(x,y)$')
b(ax,6,1.03,4.1,.78,r'$\exists x\,\exists y\,P(x,y)$')
for a,c in [((4.9,5.31),(3.6,4.62)),((7.1,5.31),(8.4,4.62)),((3,3.8),(3,3.04)),((9,3.8),(9,3.04)),((3.65,2.2),(5.2,1.43)),((8.35,2.2),(6.8,1.43))]: arr(ax,a,c)
t(ax,6,.25,'前提：个体域非空；所有节点使用同一个二元谓词 P(x,y)',14,color=gray)
save(fig,'implication')

# 2: actual variable capture diagram with quantifier scope and free variable.
fig,ax=plt.subplots(figsize=(12,5.6))
ax.set(xlim=(0,12),ylim=(0,5.7));ax.axis('off')
t(ax,6,5.38,'UI 代入：如何发生变量捕获',25)
t(ax,6,4.92,'从全称公式消去最外层量词时，替代变量不得被内部量词重新约束',16,color=gray)
for x,color,head in [(2.05,blue,'原公式'),(6,red,'错误代入'),(9.95,teal,'正确代入')]:
 ax.add_patch(FancyBboxPatch((x-1.8,1.05),3.6,3.25,boxstyle='round,pad=.04,rounding_size=.13',edgecolor=color,linewidth=2.3,facecolor='#fafcfd'))
 t(ax,x,4.02,head,20,color=color)
# formula + literal scoped target bands
for x,formula in [(2.05,r'$\forall x\;\exists y\;G(x,y)$'),(6,r'$\exists y\;G(y,y)$'),(9.95,r'$\exists y\;G(z,y)$')]:t(ax,x,3.43,formula,24,math=True)
# nesting is visible by graduated rectangles representing quantifier scopes
ax.add_patch(FancyBboxPatch((.58,2.12),2.94,.78,boxstyle='round,pad=.04',facecolor='#e7eff8',edgecolor=blue,lw=1.5))
ax.add_patch(FancyBboxPatch((1.05,2.26),2.05,.49,boxstyle='round,pad=.03',facecolor='#d7eee8',edgecolor=teal,lw=1.5))
t(ax,2.05,2.5,r'$G(x,y)$',21,math=True)
t(ax,2.05,1.73,'外层 x、内层 y 各有归属',14)
ax.add_patch(FancyBboxPatch((4.62,2.12),2.76,.78,boxstyle='round,pad=.04',facecolor=redbg,edgecolor=red,lw=1.6))
t(ax,6,2.5,r'$G(y,y)$',21,math=True)
t(ax,6,1.73,'两个 y 都被 ∃y 约束',14,color=red)
ax.add_patch(FancyBboxPatch((8.56,2.12),2.78,.78,boxstyle='round,pad=.04',facecolor=greenbg,edgecolor=teal,lw=1.6))
t(ax,9.95,2.5,r'$G(z,y)$',21,math=True)
t(ax,9.95,1.73,'z 仍自由；y 受 ∃y 约束',14,color=teal)
arr(ax,(3.88,2.6),(4.42,2.6),red,18,2)
arr(ax,(7.83,2.6),(8.35,2.6),teal,18,2)
t(ax,6,.61,r'$\forall x\exists yG(x,y)\;\Rightarrow\;\exists yG(z,y)$',19,math=True)
t(ax,6,.21,'合法代入；不能把 x 直接替换成受内部量词约束的 y',14,color=red)
save(fig,'capture')

# 3: finite model for quantifier swap
fig,ax=plt.subplots(figsize=(10.8,6.4))
ax.set(xlim=(0,10.8),ylim=(0,6.6));ax.axis('off')
t(ax,5.4,6.25,'量词顺序的反例：每行有真值，不代表存在全真列',23)
t(ax,5.4,5.67,r'$D=\{1,2\},\qquad P(x,y):\ x=y$',24,math=True)
left=1.0;top=4.77;cell=1.42
for i in range(2):
 for j in range(2):
  yes=i==j
  ax.add_patch(Rectangle((left+j*cell,top-(i+1)*cell),cell,cell,facecolor=greenbg if yes else redbg,edgecolor=line,lw=2))
  # no glyph dependent check icons: circle / diagonal cross drawn as vectors
  center=(left+(j+.5)*cell,top-(i+.5)*cell)
  if yes:ax.add_patch(Circle(center,.25,facecolor=teal,edgecolor='white',lw=2))
  else:
   cx,cy=center;ax.plot([cx-.19,cx+.19],[cy-.19,cy+.19],color=red,lw=4);ax.plot([cx-.19,cx+.19],[cy+.19,cy-.19],color=red,lw=4)
for j in range(2):t(ax,left+(j+.5)*cell,top+.32,f'y={j+1}',17,math=True)
for i in range(2):t(ax,left-.42,top-(i+.5)*cell,f'x={i+1}',17,math=True)
t(ax,2.46,1.15,'每行都有绿色圆点',18,color=teal)
t(ax,7.35,4.38,r'$\forall x\exists y\,P(x,y)$',27,math=True)
t(ax,7.35,3.85,'成立：每个 x 可各选一个 y',17,color=teal)
t(ax,7.35,2.68,r'$\exists y\forall x\,P(x,y)$',27,math=True)
t(ax,7.35,2.13,'不成立：不存在全部为真的列',17,color=red)
t(ax,5.4,.4,'所以不能把 ∀x∃y 直接改写为 ∃y∀x',19,color=red)
save(fig,'matrix')

# 4: witness selection with distinct existence claims
fig,ax=plt.subplots(figsize=(11.5,5.2));ax.set(xlim=(0,11.5),ylim=(0,5.35));ax.axis('off')
t(ax,5.75,5.03,'EI 见证不能复用：两个存在事实可以由不同对象实现',22)
t(ax,5.75,4.48,'D 为整数集；Q(x) 表示“x 是偶数”',17,color=gray)
# number line with separate values and recognized witnesses
ax.plot([1.45,10.1],[2.8,2.8],color=gray,lw=3)
for n in (1,2,3,4):
 x=1.9+(n-1)*2.45
 ax.plot([x,x],[2.65,2.95],color=ink,lw=2)
 t(ax,x,2.38,str(n),19)
ax.add_patch(Circle((4.35,2.8),.29,facecolor=greenbg,edgecolor=teal,lw=4))
ax.add_patch(Circle((6.8,2.8),.29,facecolor=redbg,edgecolor=red,lw=4))
arr(ax,(3.3,3.95),(4.2,3.16),teal,22)
arr(ax,(7.95,3.95),(6.92,3.16),red,22)
t(ax,2.85,4.04,r'$\exists x\,Q(x)$',23,math=True,color=teal)
t(ax,8.55,4.04,r'$\exists x\,\neg Q(x)$',23,math=True,color=red)
t(ax,3.05,1.48,r'$Q(a),\quad a=2$',23,math=True,color=teal)
t(ax,8.40,1.48,r'$\neg Q(b),\quad b=3$',23,math=True,color=red)
t(ax,5.75,.45,'两个存在命题都真，但不能推出 Q(a) 与 ¬Q(a) 同时成立',18,color=ink)
save(fig,'witness')

# 5 proof graph
fig,ax=plt.subplots(figsize=(12,5.0));ax.set(xlim=(0,12),ylim=(0,5.25));ax.axis('off')
t(ax,6,4.98,'证明路径：先为存在命题取新见证，再用全称命题匹配',22)
b(ax,3.1,4.0,4.5,.70,r'$\exists x\,F(x)$',fontsize=24)
b(ax,8.9,4.0,4.9,.70,r'$\forall x\,(F(x)\to G(x))$',fontsize=23)
b(ax,3.1,2.88,4.5,.70,r'$F(c)$',fontsize=24)
b(ax,8.9,2.88,4.9,.70,r'$F(c)\to G(c)$',fontsize=23)
arr(ax,(3.1,3.62),(3.1,3.26));arr(ax,(8.9,3.62),(8.9,3.26))
t(ax,4.15,3.45,'EI：新见证 c',13,color=blue,ha='left')
t(ax,9.65,3.45,'UI：匹配 c',13,color=blue,ha='left')
b(ax,4.05,1.43,3.4,.7,r'$G(c)$',fontsize=24)
b(ax,8.28,1.43,3.9,.7,r'$\exists x\,G(x)$',fontsize=24)
arr(ax,(3.1,2.50),(3.68,1.81));arr(ax,(8.3,2.5),(4.5,1.8))
t(ax,6,2.4,'假言推理',14,color=blue)
arr(ax,(5.82,1.43),(6.28,1.43));t(ax,6.08,1.91,'EG',15,color=blue)
t(ax,6,.36,'见证 c 不是预先指定的对象；最终结论中不再依赖 c',16,color=red)
save(fig,'proof')

# 6: quantifier distribution failure via 2-element model
fig,ax=plt.subplots(figsize=(11.5,7.5));ax.set(xlim=(0,11.5),ylim=(0,7.65));ax.axis('off')
t(ax,5.75,7.29,'量词分配律反例：两种逆向推理都不成立',23)
t(ax,5.75,6.72,r'$D=\{1,2\},\quad A(x):x=1,\quad B(x):x=2$',23,math=True)
headers=['x','A(x)','B(x)','A(x)∨B(x)','A(x)∧B(x)']
width=[1.3,1.5,1.5,2.3,2.3];starts=[.6,1.9,3.4,4.9,7.2]
for st,w,h in zip(starts,width,headers):
 ax.add_patch(Rectangle((st,5.38),w,.62,facecolor='#e8f0f7',edgecolor=line,lw=1))
 t(ax,st+w/2,5.69,h,16)
for i,v in enumerate([('1','真','假','真','假'),('2','假','真','真','假')]):
 y=4.61-i*.74
 for st,w,c in zip(starts,width,v):
  ax.add_patch(Rectangle((st,y),w,.74,facecolor=greenbg if c=='真' else redbg if c=='假' else 'white',edgecolor=line,lw=1))
  t(ax,st+w/2,y+.37,c,17,color=teal if c=='真' else red if c=='假' else ink)
# Two logical failures shown independently, with truthful value calculations.
ax.plot([.8,10.75],[3.66,3.66],color=line,lw=1.3)
t(ax,3.2,3.20,r'$\forall x\,[A(x)\vee B(x)]$',20,math=True)
t(ax,3.2,2.81,'真：每个 x 至少满足一个',16,color=teal)
t(ax,8.4,3.20,r'$(\forall xA(x))\vee(\forall xB(x))$',19,math=True)
t(ax,8.4,2.81,'假：没有一项对所有 x 成立',16,color=red)
ax.plot([.8,10.75],[2.32,2.32],color=line,lw=1.2)
t(ax,3.2,1.89,r'$(\exists xA(x))\wedge(\exists xB(x))$',19,math=True)
t(ax,3.2,1.49,'真：两个性质各自有见证',16,color=teal)
t(ax,8.4,1.89,r'$\exists x\,[A(x)\wedge B(x)]$',20,math=True)
t(ax,8.4,1.49,'假：没有对象同时满足两者',16,color=red)
t(ax,5.75,.56,'真正成立的方向：右上项 ⇒ 左上项；右下项 ⇒ 左下项',16,color=gray)
save(fig,'distribution')

# Adapt old prose into Obsidian-centric markdown, preserve all original worked proofs.
md=orig.read_text(encoding='utf-8')
# remove typesetting commands that break Markdown preview
md=re.sub(r'^\\needspace\{[^\n]*\}\s*$', '', md, flags=re.M)
# convert existing PNG links to vault-root Wikilinks
old={
 'figures/图1_量词推出关系.png':'implication',
 'figures/图2_四条量词规则.png':'capture',
 'figures/图3_量词换序反例.png':'matrix',
 'figures/图4_典型证明路线.png':'proof'
}
for old_path,key in old.items():
 pattern=r'!\[([^\]\n]*)\]\('+re.escape(old_path)+r'\)'
 md=re.sub(pattern,lambda m:'![['+f'Assets/{assets}/images/{name_map[key]}.png'+'|'+m.group(1)+']]',md)
# Replace card figure positioning in the rules summary with a contextual illustration below UI instead.
capture_link='![['+f'Assets/{assets}/images/{name_map["capture"]}.png'+'|图：UI 中把变量 y 代入 x 会造成捕获，换用自由变量 z 才合法]]'
md=md.replace('![['+f'Assets/{assets}/images/{name_map["capture"]}.png'+'|四条量词推理规则及使用限制]]\n\n*说明：左列是两条量词消去规则，右列是两条量词引入规则。特别把 EI 画为“在证明中引入见证”，避免误认为存在命题可以逻辑地推出某个预先指定的常量命题。*\n\n','')
ui_needle='对于课件中的 $G(x,y):x>y$、$D=\\mathbb Z$，原式是真的，而 $\\exists y(y>y)$ 是假的，因此错误十分直观。'
assert ui_needle in md
md=md.replace(ui_needle,ui_needle+'\n\n'+capture_link+'\n\n*图：外层全称量词消去后，不能让代入的变量成为内部存在量词的约束变量。*')
# add actual new graph to distribution and witness sections
needle='由此可见：**公式左、右两边只是有时同真，并不构成等值式。**'
assert needle in md
md=md.replace(needle,needle+'\n\n![['+f'Assets/{assets}/images/{name_map["distribution"]}.png'+'|图：两个对象分别满足 A 和 B，说明全称对析取、存在对合取均不能反向分配]]\n\n*图：两对象分别满足不同性质，直接展示错误的逆向分配。*')
needle='**不能**给两个前提都用同一个新见证 $a$，否则会捏造出 $Q(a)\\land\\neg Q(a)$ 的矛盾。比如“存在偶数”和“存在非偶数”都真，并不意味着有同一个整数既是偶数又不是偶数。'
assert needle in md
md=md.replace(needle,needle+'\n\n![['+f'Assets/{assets}/images/{name_map["witness"]}.png'+'|图：偶数与非偶数的存在见证可以不同，EI 不得复用同一新名字]]\n\n*图：第一个存在前提由 2 作见证，第二个由 3 作见证。*')
# fix old inaccurate image references
md=md.replace('这正是图2所示错误的根源。','这正是前面的“量词换序有限域反例”所揭示的错误根源。')
md=md.replace('已在图2举出反例。','已在“量词换序有限域反例”中说明。')
md=md.replace('使用图2对角线反例验证','使用上文“量词换序有限域反例”验证')
md=md.replace('整理说明：** 4张插图均为依据课件重新绘制的独立示意图；图1的箭头表达单向推出，图2以明确的有限个体域展示反例，图3区别 EI 见证与任意常量，图4逐步对应证明规则。',
              '整理说明：** 本笔记保留课件 5.1—5.3 的主体结构，补充必要推导和四道课堂练习的参考证明。6 张插图分别解释双变量推出、量词分配的有限域反例、量词换序的有限域反例、UI 变量捕获、EI 见证复用以及 EI—UI—EG 证明流程；每张图对应具体概念、反例或操作机制。')
# add academic note callouts at key points, not wholesale decoration
md=md.replace('**课件第9—10页**，务必分清两种情况：', '> [!important] 分配律的成立范围\n> 只有 **全称量词对合取** 和 **存在量词对析取** 是无条件双向分配。另两种组合只能在一个方向上推出。\n\n**课件第9—10页**，务必分清两种情况：')
md=md.replace('**课件第17—20页**：如果一个公式等值地写成', '> [!note] 前束范式与等值变形\n> 要得到前束范式，必须保持等值；量词不能仅凭“把它挪到最前面”就完成变换。\n\n**课件第17—20页**：如果一个公式等值地写成')
md=md.replace('**规则思想：** 若 $\\exists xP(x)$，我们知道', '> [!warning] EI 的形式限制\n> 从存在命题获得的是一个**新的、未知的见证**，绝不是证明了某个预先指定对象满足它。若含额外自由参数，必须防止见证依赖该参数而错误地全称概括。\n\n**规则思想：** 若 $\\exists xP(x)$，我们知道')
md=md.replace('**课件第56页的“**先 EI，后 UI**”','**课件第56页的“**先 EI，后 UI**”')
# repair textual label from initial note
md=md.replace('这正是图2所示错误的根源','这正是上文量词换序反例揭示的错误根源')
# add info about source vs supplementary explanation
md=md.replace('**课件依据**：《第7讲+谓词逻辑推理.pdf》，共62页，按课件', '**课件依据**：《第7讲+谓词逻辑推理.pdf》，共62页。课件内容与为辅助理解补充的说明、反例及参考证明已在相关位置区分。笔记按课件')
# convert a difficult already-expanded proof into foldable example, but keep the worked proof in main text; avoid core hidden.
md=md.replace('### 6.2 习题二：用归谬法证明', '### 6.2 习题二：用归谬法证明')
# ensure images are explicitly declared and named in intro
md=md.replace('---\n\n## 一、全章结构', '> [!info] 插图归档说明\n> 本笔记采用 Obsidian Wiki 附件链接：图片统一存放在 Vault 根目录的 `Assets/` 中。将 ZIP 内的唯一资源文件夹整体复制到 `Assets/`，再把本 Markdown 放到任意笔记目录即可。普通 Markdown/HTML 工具需要额外处理 Wiki 链接。\n\n---\n\n## 一、全章结构')
# Wrap some examples in syntactically valid callouts, without indenting tables
md=md.replace('**统一反例：** 设 $D=\\{1,2\\}$，', '> [!example] 分配律不成立的同一反例\n> 设 $D=\\{1,2\\}$，').replace('**统一反例：** 设 $D=\\{1,2\\}$，','> [!example] 分配律不成立的同一反例\n> 设 $D=\\{1,2\\}$，')
# Complete the example callout while keeping the remainder as normal prose.
md=md.replace('> 设 $D=\\{1,2\\}$，$A(x)$ 表示 $x=1$，$B(x)$ 表示 $x=2$。则：\n\n- 对每个', '> 设 $D=\\{1,2\\}$，$A(x)$ 表示 $x=1$，$B(x)$ 表示 $x=2$。则：\n>\n> - 对每个')
md=md.replace('故它们的析取假。\n- $\\exists', '故它们的析取假。\n> - $\\exists')
# final closing note audited
md=md.replace('图1的箭头表达单向推出，图2以明确的有限个体域展示反例，图3区别 EI 见证与任意常量，图4逐步对应证明规则。','图示均与所在知识点对应，箭头仅用于确实成立的推出或操作步骤。')
md=md.replace('每张图对应具体概念、反例或操作机制。笔记在不更换课件章节框架的前提下，补充了必要的推导步骤、规则适用条件及课件习题参考解答。', '每张图对应具体概念、反例或操作机制。')
md_path=OUT/'第7讲_谓词逻辑推理_4.3规范版.md'
md_path.write_text(md,encoding='utf-8')
# source of figures is copy of exact generating script for reproducibility
shutil.copy2(__file__,source_dir/'build_bundle.py')

# QA references, math delimiters, image count & raster sizes
refs=re.findall(r'!\[\[([^\]]+?\.png)(?:\|[^\]]*)?\]\]',md)
assert len(refs)==6,refs
assert len(refs)==len(set(refs))
for rel in refs:
 assert rel.startswith('Assets/'+assets+'/images/'),rel
 assert (OUT/rel.removeprefix('Assets/')).is_file(),rel
 assert Image.open(OUT/rel.removeprefix('Assets/')).verify() is None
assert '\\needspace' not in md
assert all(md.count(delim)%2==0 for delim in ['$$'])
for k,fn in name_map.items():
 assert (img_dir/(fn+'.png')).is_file() and (source_dir/(fn+'.svg')).is_file()
# validate SVG as XML
import xml.etree.ElementTree as ET
for svg in source_dir.glob('*.svg'):ET.parse(svg)
# metadata only in source: source depends on our pipeline; original PDFs and fonts not included
zip_path=BASE/'第7讲_谓词逻辑推理_4.3规范版.zip'
with zipfile.ZipFile(zip_path,'w',zipfile.ZIP_DEFLATED,compresslevel=7) as z:
 z.write(md_path,md_path.relative_to(OUT))
 for p in root.rglob('*'):
  if p.is_file():z.write(p,p.relative_to(OUT))
with zipfile.ZipFile(zip_path) as z:
 assert z.testzip() is None
 print('ZIP PATH:',zip_path)
 print('ROOT:',sorted({p.split('/')[0] for p in z.namelist()}))
 print('CONTENTS:',len(z.namelist()),'files; MD',len(md),'chars; figs',len(refs))
 print('IMAGE SIZES:',{k:Image.open(img_dir/(fn+'.png')).size for k,fn in name_map.items()})
print('MD PATH:',md_path)
print('ASSET FOLDER:',assets)
