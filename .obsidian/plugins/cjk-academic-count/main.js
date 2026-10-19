(function () {
  const DEFAULT_SETTINGS = {
    countWhitespaceInPrimary: false,
    stripFrontmatter: true,
    stripMarkdownMarkup: true,
    locale: "en-US",
  };

  const LINE_BREAK_RE = /\r\n?/g;
  const HORIZONTAL_SPACE_RE = /[\t\f\v \u00a0\u1680\u2000-\u200a\u202f\u205f\u3000]/u;
  const WHITESPACE_RE = /\s/u;
  const HAN_RE = /\p{Script=Han}/u;
  const HIRAGANA_RE = /\p{Script=Hiragana}/u;
  const KATAKANA_RE = /\p{Script=Katakana}/u;
  const HANGUL_RE = /\p{Script=Hangul}/u;
  const DIGIT_RE = /\p{Number}/u;
  const LATIN_RE = /\p{Script=Latin}/u;
  const PUNCTUATION_RE = /\p{Punctuation}/u;
  const NON_CJK_WORD_TOKEN_RE = /[\p{Script=Latin}\p{Number}]+(?:[.'’_+\-–—/][\p{Script=Latin}\p{Number}]+)*/gu;
  const NUMBER_LOCALES = {
    en: "en-US",
    zh: "zh-CN",
    "zh-TW": "zh-TW",
    ja: "ja-JP",
    ko: "ko-KR",
  };

  const I18N = {
    en: {
      total: "Total",
      selected: "Selected",
      academicCharsUnit: "academic chars",
      academicCharacters: "Academic characters",
      hanCharacters: "Han characters",
      kana: "Kana",
      hangul: "Hangul",
      referenceMetrics: "Reference metrics",
      charactersWithoutWhitespace: "Characters without whitespace",
      charactersWithWhitespace: "Characters with whitespace",
      wordLikeCount: "Word-like count",
      nonCjkWordTokens: "Non-CJK word tokens",
      numbers: "Numbers",
      punctuation: "Punctuation",
      latin: "Latin",
      other: "Other",
      ignoreFrontmatterName: "Ignore YAML frontmatter",
      ignoreFrontmatterDesc: "Exclude the leading --- metadata block from academic character counts.",
      ignoreMarkdownName: "Ignore common Markdown markup",
      ignoreMarkdownDesc:
        "Remove heading markers, emphasis markers, link URLs, table pipes, and similar Markdown syntax for a preview-like count.",
    },
    zh: {
      total: "全文",
      selected: "选中",
      academicCharsUnit: "学术字",
      academicCharacters: "学术字数",
      hanCharacters: "汉字/日语汉字",
      kana: "假名",
      hangul: "韩文",
      referenceMetrics: "参考指标",
      charactersWithoutWhitespace: "字符数（不计空白）",
      charactersWithWhitespace: "字符数（含空白）",
      wordLikeCount: "Word 式字数",
      nonCjkWordTokens: "非 CJK 词",
      numbers: "数字",
      punctuation: "标点",
      latin: "拉丁",
      other: "其他",
      ignoreFrontmatterName: "忽略 YAML frontmatter",
      ignoreFrontmatterDesc: "开启后，笔记开头的 --- 元数据块不计入学术字数。",
      ignoreMarkdownName: "忽略常见 Markdown 标记",
      ignoreMarkdownDesc: "移除标题符号、强调符号、链接 URL、表格竖线等常见 Markdown 语法，更接近预览文本。",
    },
    "zh-TW": {
      total: "全文",
      selected: "選取",
      academicCharsUnit: "學術字",
      academicCharacters: "學術字數",
      hanCharacters: "漢字/日語漢字",
      kana: "假名",
      hangul: "韓文",
      referenceMetrics: "參考指標",
      charactersWithoutWhitespace: "字元數（不計空白）",
      charactersWithWhitespace: "字元數（含空白）",
      wordLikeCount: "Word 式字數",
      nonCjkWordTokens: "非 CJK 詞",
      numbers: "數字",
      punctuation: "標點",
      latin: "拉丁",
      other: "其他",
      ignoreFrontmatterName: "忽略 YAML frontmatter",
      ignoreFrontmatterDesc: "開啟後，筆記開頭的 --- metadata 區塊不計入學術字數。",
      ignoreMarkdownName: "忽略常見 Markdown 標記",
      ignoreMarkdownDesc: "移除標題符號、強調符號、連結 URL、表格直線等常見 Markdown 語法，更接近預覽文字。",
    },
    ja: {
      total: "全体",
      selected: "選択",
      academicCharsUnit: "学術文字",
      academicCharacters: "学術文字数",
      hanCharacters: "漢字",
      kana: "仮名",
      hangul: "ハングル",
      referenceMetrics: "参考指標",
      charactersWithoutWhitespace: "空白なし文字数",
      charactersWithWhitespace: "空白込み文字数",
      wordLikeCount: "Word 風カウント",
      nonCjkWordTokens: "非 CJK 語",
      numbers: "数字",
      punctuation: "句読点",
      latin: "ラテン文字",
      other: "その他",
      ignoreFrontmatterName: "YAML frontmatter を除外",
      ignoreFrontmatterDesc: "ノート先頭の --- メタデータブロックを学術文字数から除外します。",
      ignoreMarkdownName: "一般的な Markdown 記法を除外",
      ignoreMarkdownDesc:
        "見出し記号、強調記号、リンク URL、表の縦線などの Markdown 構文を除外し、プレビューに近い数え方にします。",
    },
    ko: {
      total: "전체",
      selected: "선택",
      academicCharsUnit: "학술 문자",
      academicCharacters: "학술 문자 수",
      hanCharacters: "한자",
      kana: "가나",
      hangul: "한글",
      referenceMetrics: "참고 지표",
      charactersWithoutWhitespace: "공백 제외 문자 수",
      charactersWithWhitespace: "공백 포함 문자 수",
      wordLikeCount: "Word식 단어 수",
      nonCjkWordTokens: "비 CJK 단어",
      numbers: "숫자",
      punctuation: "문장 부호",
      latin: "라틴 문자",
      other: "기타",
      ignoreFrontmatterName: "YAML frontmatter 제외",
      ignoreFrontmatterDesc: "노트 맨 앞의 --- 메타데이터 블록을 학술 문자 수에서 제외합니다.",
      ignoreMarkdownName: "일반 Markdown 마크업 제외",
      ignoreMarkdownDesc:
        "제목 기호, 강조 기호, 링크 URL, 표 구분선 등 일반적인 Markdown 문법을 제외하여 미리보기와 가까운 방식으로 계산합니다.",
    },
  };

  function normalizeLineBreaks(text) {
    return String(text ?? "").replace(LINE_BREAK_RE, "\n");
  }

  function stripFrontmatter(text) {
    return text.replace(/^---\n[\s\S]*?\n---(?:\n|$)/, "");
  }

  function stripMarkdownMarkup(text) {
    let value = text;

    value = value.replace(/%%[\s\S]*?%%/g, "");
    value = value.replace(/^```[\w-]*[^\n]*$/gm, "");
    value = value.replace(/^~~~[\w-]*[^\n]*$/gm, "");
    value = value.replace(/`([^`\n]+)`/g, "$1");
    value = value.replace(/!\[\[[^\]]+\]\]/g, "");
    value = value.replace(/!\[[^\]]*]\([^)]+\)/g, "");
    value = value.replace(/\[\[([^\]|]+)\|([^\]]+)]]/g, "$2");
    value = value.replace(/\[\[([^\]#|]+)(?:#[^\]|]+)?]]/g, "$1");
    value = value.replace(/\[([^\]]+)]\([^)]+\)/g, "$1");
    value = value.replace(/<[^>\n]+>/g, "");
    value = value.replace(/^\s{0,3}#{1,6}\s+/gm, "");
    value = value.replace(/^\s{0,3}>\s?(?:\[\![^\]]+]\s*)?/gm, "");
    value = value.replace(/^\s*(?:[-*+]|\d+[.)])\s+/gm, "");
    value = value.replace(/^\s*\[[ xX-]]\s+/gm, "");
    value = value.replace(/^\s*\[\^[^\]]+]:\s*/gm, "");
    value = value.replace(/\[\^[^\]]+]/g, "");
    value = value.replace(/(\*\*|__)([\s\S]*?)\1/g, "$2");
    value = value.replace(/(\*|_)([^*_]+?)\1/g, "$2");
    value = value.replace(/~~([\s\S]*?)~~/g, "$1");
    value = value.replace(/==([\s\S]*?)==/g, "$1");
    value = value.replace(/^\s*\|?[\s:|.-]+\|[\s:|.-]*$/gm, "");
    value = value.replace(/^\s*\|(.+)\|\s*$/gm, "$1");
    value = value.replace(/\|/g, "");

    return value;
  }

  function prepareText(text, settings) {
    let value = normalizeLineBreaks(text);
    if (settings.stripFrontmatter) {
      value = stripFrontmatter(value);
    }
    if (settings.stripMarkdownMarkup) {
      value = stripMarkdownMarkup(value);
    }
    return value;
  }

  function segmentText(text) {
    if (typeof Intl !== "undefined" && typeof Intl.Segmenter === "function") {
      const segmenter = new Intl.Segmenter(undefined, { granularity: "grapheme" });
      return Array.from(segmenter.segment(text), (part) => part.segment);
    }
    return Array.from(text);
  }

  function isLineBreak(segment) {
    return segment === "\n";
  }

  function isHorizontalSpace(segment) {
    return HORIZONTAL_SPACE_RE.test(segment);
  }

  function isWhitespace(segment) {
    return WHITESPACE_RE.test(segment);
  }

  function classifySegment(segment) {
    if (isWhitespace(segment)) return "whitespace";
    if (HAN_RE.test(segment)) return "han";
    if (HIRAGANA_RE.test(segment) || KATAKANA_RE.test(segment)) return "kana";
    if (HANGUL_RE.test(segment)) return "hangul";
    if (DIGIT_RE.test(segment)) return "digits";
    if (PUNCTUATION_RE.test(segment)) return "punctuation";
    if (LATIN_RE.test(segment)) return "latin";
    return "other";
  }

  function countNonCjkWordTokens(text) {
    const matches = text.match(NON_CJK_WORD_TOKEN_RE);
    return matches ? matches.length : 0;
  }

  function analyzeText(text, settings = DEFAULT_SETTINGS) {
    const prepared = prepareText(text, { ...DEFAULT_SETTINGS, ...settings });
    const segments = segmentText(prepared);
    const breakdown = {
      han: 0,
      kana: 0,
      hangul: 0,
      digits: 0,
      punctuation: 0,
      latin: 0,
      other: 0,
      whitespace: 0,
    };

    let charactersNoSpaces = 0;
    let charactersWithSpaces = 0;

    for (const segment of segments) {
      const bucket = classifySegment(segment);
      breakdown[bucket] += 1;

      if (!isWhitespace(segment)) {
        charactersNoSpaces += 1;
      }
      if (!isLineBreak(segment) && (!isWhitespace(segment) || isHorizontalSpace(segment))) {
        charactersWithSpaces += 1;
      }
    }

    const academicCharacters = breakdown.han + breakdown.kana + breakdown.hangul;
    const nonCjkWordTokens = countNonCjkWordTokens(prepared);
    const wordLikeWords = academicCharacters + nonCjkWordTokens;

    return {
      characters: settings.countWhitespaceInPrimary ? charactersWithSpaces : charactersNoSpaces,
      charactersNoSpaces,
      charactersWithSpaces,
      academicCharacters,
      cjTextCharacters: academicCharacters,
      nonCjWordTokens: nonCjkWordTokens,
      wordLikeWords,
      breakdown,
    };
  }

  function comparePositions(a, b) {
    if (a.line !== b.line) return a.line - b.line;
    return a.ch - b.ch;
  }

  function selectedTextFromEditor(editor) {
    if (!editor) return "";
    if (typeof editor.listSelections === "function" && typeof editor.getRange === "function") {
      const parts = [];
      for (const selection of editor.listSelections()) {
        const anchor = selection.anchor;
        const head = selection.head;
        if (!anchor || !head || comparePositions(anchor, head) === 0) continue;
        const from = comparePositions(anchor, head) <= 0 ? anchor : head;
        const to = comparePositions(anchor, head) <= 0 ? head : anchor;
        parts.push(editor.getRange(from, to));
      }
      return parts.join("");
    }
    if (typeof editor.getSelection === "function") {
      return editor.getSelection();
    }
    return "";
  }

  function formatNumber(value, locale) {
    return Number(value).toLocaleString(locale || "en-US");
  }

  function normalizeLanguageTag(rawLanguage) {
    if (!rawLanguage) return "en";
    const value = String(rawLanguage).replace(/_/g, "-").toLowerCase();
    if (value.startsWith("zh-tw") || value.startsWith("zh-hant") || value.startsWith("zh-hk") || value.startsWith("zh-mo")) {
      return "zh-TW";
    }
    if (value.startsWith("zh")) return "zh";
    if (value.startsWith("ja")) return "ja";
    if (value.startsWith("ko")) return "ko";
    return "en";
  }

  function getLanguageSignal() {
    if (typeof window !== "undefined" && window.localStorage) {
      try {
        const storageLanguage = window.localStorage.getItem("language");
        return storageLanguage || "en";
      } catch (_error) {
        // Fall through to other language signals.
      }
    }
    if (typeof document !== "undefined" && document.documentElement?.lang) {
      return document.documentElement.lang;
    }
    if (typeof window !== "undefined" && typeof window.moment?.locale === "function") {
      return window.moment.locale();
    }
    if (typeof navigator !== "undefined") {
      return navigator.languages?.[0] || navigator.language;
    }
    return "en";
  }

  function getUiLanguage() {
    return normalizeLanguageTag(getLanguageSignal());
  }

  function getStrings(language) {
    return I18N[language] || I18N.en;
  }

  function getNumberLocale(language) {
    return NUMBER_LOCALES[language] || NUMBER_LOCALES.en;
  }

  function buildStatusSegment(labelKey, analysis, strings, locale) {
    return `${strings[labelKey]} ${formatNumber(analysis.academicCharacters, locale)} ${strings.academicCharsUnit}`;
  }

  function buildTooltip(labelKey, analysis, strings, locale) {
    const lines = [
      `${strings[labelKey]}`,
      `${strings.academicCharacters}: ${formatNumber(analysis.academicCharacters, locale)}`,
      `${strings.hanCharacters}: ${formatNumber(analysis.breakdown.han, locale)}`,
      `${strings.kana}: ${formatNumber(analysis.breakdown.kana, locale)}`,
      `${strings.hangul}: ${formatNumber(analysis.breakdown.hangul, locale)}`,
      "",
      strings.referenceMetrics,
      `${strings.charactersWithoutWhitespace}: ${formatNumber(analysis.charactersNoSpaces, locale)}`,
      `${strings.charactersWithWhitespace}: ${formatNumber(analysis.charactersWithSpaces, locale)}`,
      `${strings.wordLikeCount}: ${formatNumber(analysis.wordLikeWords, locale)}`,
      `${strings.nonCjkWordTokens}: ${formatNumber(analysis.nonCjWordTokens, locale)}`,
      `${strings.numbers}: ${formatNumber(analysis.breakdown.digits, locale)}`,
      `${strings.punctuation}: ${formatNumber(analysis.breakdown.punctuation, locale)}`,
      `${strings.latin}: ${formatNumber(analysis.breakdown.latin, locale)}`,
      `${strings.other}: ${formatNumber(analysis.breakdown.other, locale)}`,
    ];
    return lines.join("\n");
  }

  if (typeof module !== "undefined" && module.exports) {
    module.exports = {
      DEFAULT_SETTINGS,
      analyzeText,
      getStrings,
      normalizeLanguageTag,
      prepareText,
      segmentText,
      selectedTextFromEditor,
    };
  }

  let obsidian;
  try {
    if (typeof require !== "function") return;
    obsidian = require("obsidian");
  } catch (_error) {
    return;
  }

  const { MarkdownView, Plugin, PluginSettingTab, Setting } = obsidian;

  class CjkAcademicCountPlugin extends Plugin {
    async onload() {
      this.settings = { ...DEFAULT_SETTINGS, ...(await this.loadData()) };
      this.statusBarItem = this.addStatusBarItem();
      this.statusBarItem.addClass("cjk-academic-count-status");
      this.updateTimer = null;

      this.addSettingTab(new CjkAcademicCountSettingTab(this.app, this));

      this.registerEvent(this.app.workspace.on("active-leaf-change", () => this.scheduleUpdate()));
      this.registerEvent(this.app.workspace.on("file-open", () => this.scheduleUpdate()));
      this.registerEvent(this.app.workspace.on("editor-change", () => this.scheduleUpdate()));
      this.registerDomEvent(document, "selectionchange", () => this.scheduleUpdate());
      this.registerDomEvent(document, "keyup", () => this.scheduleUpdate());
      this.registerDomEvent(document, "mouseup", () => this.scheduleUpdate());
      this.registerDomEvent(document, "touchend", () => this.scheduleUpdate());

      this.scheduleUpdate();
    }

    onunload() {
      if (this.updateTimer !== null) {
        window.clearTimeout(this.updateTimer);
      }
    }

    async saveSettings() {
      await this.saveData(this.settings);
      this.scheduleUpdate();
    }

    scheduleUpdate() {
      if (this.updateTimer !== null) {
        window.clearTimeout(this.updateTimer);
      }
      this.updateTimer = window.setTimeout(() => {
        this.updateTimer = null;
        this.updateStatus();
      }, 80);
    }

    updateStatus() {
      const view = this.app.workspace.getActiveViewOfType(MarkdownView);
      const editor = view?.editor;
      if (!editor || typeof editor.getValue !== "function") {
        this.statusBarItem.setText("");
        this.statusBarItem.setAttr("title", "");
        this.statusBarItem.removeClass("has-selection");
        return;
      }

      const total = analyzeText(editor.getValue(), this.settings);
      const selectedText = selectedTextFromEditor(editor);
      const selection = selectedText ? analyzeText(selectedText, this.settings) : null;
      const language = getUiLanguage();
      const strings = getStrings(language);
      const locale = getNumberLocale(language);
      const parts = [buildStatusSegment("total", total, strings, locale)];

      if (selection && selection.characters > 0) {
        parts.push(buildStatusSegment("selected", selection, strings, locale));
        this.statusBarItem.addClass("has-selection");
      } else {
        this.statusBarItem.removeClass("has-selection");
      }

      this.statusBarItem.setText(parts.join(" | "));
      const tooltip = [buildTooltip("total", total, strings, locale)];
      if (selection) {
        tooltip.push("", buildTooltip("selected", selection, strings, locale));
      }
      this.statusBarItem.setAttr("title", tooltip.join("\n"));
    }
  }

  class CjkAcademicCountSettingTab extends PluginSettingTab {
    constructor(app, plugin) {
      super(app, plugin);
      this.plugin = plugin;
    }

    display() {
      const { containerEl } = this;
      const strings = getStrings(getUiLanguage());
      containerEl.empty();
      containerEl.createEl("h2", { text: "CJK Academic Count" });

      new Setting(containerEl)
        .setName(strings.ignoreFrontmatterName)
        .setDesc(strings.ignoreFrontmatterDesc)
        .addToggle((toggle) =>
          toggle.setValue(this.plugin.settings.stripFrontmatter).onChange(async (value) => {
            this.plugin.settings.stripFrontmatter = value;
            await this.plugin.saveSettings();
          }),
        );

      new Setting(containerEl)
        .setName(strings.ignoreMarkdownName)
        .setDesc(strings.ignoreMarkdownDesc)
        .addToggle((toggle) =>
          toggle.setValue(this.plugin.settings.stripMarkdownMarkup).onChange(async (value) => {
            this.plugin.settings.stripMarkdownMarkup = value;
            await this.plugin.saveSettings();
          }),
        );
    }
  }

  module.exports = CjkAcademicCountPlugin;
})();

/* nosourcemap */