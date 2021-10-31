(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(ansi-color-faces-vector
   [default default default italic underline success warning error])
 '(blacken-line-length 79)
 '(custom-enabled-themes '(misterioso))
 '(custom-safe-themes
   '("89885317e7136d4e86fb842605d47d8329320f0326b62efa236e63ed4be23c58" "7922b14d8971cce37ddb5e487dbc18da5444c47f766178e5a4e72f90437c0711" default))
 '(elpy-rpc-python-command "/bin/python3.8")
 '(fci-rule-color "#37474f")
 '(global-linum-mode t)
 '(help-at-pt-display-when-idle '(flymake-overlay) nil (help-at-pt))
 '(help-at-pt-timer-delay 0.5)
 '(hl-sexp-background-color "#1c1f26")
 '(initial-buffer-choice "~/workspace/")
 '(org-agenda-files '("~/workspace/craft/gtd/"))
 '(org-babel-load-languages '((python . t) (emacs-lisp . t)))
 '(org-babel-python-command "python3")
 '(org-babel-python-mode 'python-mode)
 '(org-latex-default-table-environment "longtable")
 '(org-latex-packages-alist '(("" "" nil)))
 '(org-refile-allow-creating-parent-nodes 'confirm)
 '(org-refile-targets '((org-agenda-files :level . 1)))
 '(org-refile-use-outline-path 'file)
 '(org-src-lang-modes
   '(("plantuml" . plantuml)
     ("C" . c)
     ("C++" . c++)
     ("asymptote" . asy)
     ("bash" . sh)
     ("beamer" . latex)
     ("calc" . fundamental)
     ("cpp" . c++)
     ("ditaa" . artist)
     ("dot" . fundamental)
     ("elisp" . emacs-lisp)
     ("ocaml" . tuareg)
     ("screen" . shell-script)
     ("shell" . sh)
     ("sqlite" . sql)))
 '(org-startup-truncated nil)
 '(package-selected-packages
   '(tickscript-mode plantuml-mode org-preview-html flymake-python-pyflakes blacken flycheck elpy material-theme better-defaults))
 '(python-shell-interpreter "/bin/python3.8")
 '(tab-width 4)
 '(vc-annotate-background nil)
 '(vc-annotate-color-map
   '((20 . "#f36c60")
     (40 . "#ff9800")
     (60 . "#fff59d")
     (80 . "#8bc34a")
     (100 . "#81d4fa")
     (120 . "#4dd0e1")
     (140 . "#b39ddb")
     (160 . "#f36c60")
     (180 . "#ff9800")
     (200 . "#fff59d")
     (220 . "#8bc34a")
     (240 . "#81d4fa")
     (260 . "#4dd0e1")
     (280 . "#b39ddb")
     (300 . "#f36c60")
     (320 . "#ff9800")
     (340 . "#fff59d")
     (360 . "#8bc34a")))
 '(vc-annotate-very-old-color nil))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(flymake-error ((((class color)) (:underline "red"))))
 '(flymake-warning ((((class color)) (:underline "yellow")))))


;; =========== Basic File Management  ==============

(setq make-backup-files nil)

;; =================================================



;; =========== Basic Editing Settings ==============

(setq-default tab-width 10)

;; =================================================


;; =========== MELPA Package Support ===============

;; Enables basic packaging support

(require 'package)


;; Adds the Melpa archive to the list of available repositories

(add-to-list 'package-archives

             '("melpa" . "http://melpa.org/packages/") t)


;; Initializes the package infrastructure

(package-initialize)


;; If there are no archived package contents, refresh them

(when (not package-archive-contents)

  (package-refresh-contents))


;; Installs packages

;; myPackages contains a list of package names

(defvar myPackages

  '(better-defaults                 ;; Set up some better Emacs defaults
	elpy
	blacken
	flymake
	flymake-python-pyflakes
	org-preview-html
	plantuml-mode
    )
  )


;; Scans the list in myPackages

;; If the package listed is not already installed, install it

(mapc #'(lambda (package)

          (unless (package-installed-p package)

            (package-install package)))

      myPackages)

;; =================================================


;; ========= Python development setup =========

;; Enable elpy
(elpy-enable)

(add-hook 'python-mode-hook 'blacken-mode)

;; Enable flymake

;; Load Flymake
(require 'flymake)
;; Load Flymake-python
(require 'flymake-python-pyflakes)
;; Activate it each time python mode is turned on
(add-hook 'python-mode-hook 'flymake-python-pyflakes-load)

;; Run flymake when we open a file
;; (add-hook 'find-file-hook 'flymake-find-file-hook)

;; Underline warnings and errors from Flymake


;; Display error and warning messages in minibuffer.


;; ============================================


;; ============= org mode setup ===============



(setq org-ellipsis " :")

(add-hook 'text-mode-hook #'auto-fill-mode)

(add-hook 'org-mode-hook
          (lambda () (local-set-key (kbd "C-q") 'org-table-wrap-region)))

(add-hook 'org-mode-hook
          (lambda () (local-set-key (kbd "C-c a") 'org-agenda)))

(add-hook 'org-mode-hook
          (lambda () (local-set-key (kbd "C-c s") 'org-schedule)))


(defun org-table-wrap-to-width (width)
  "Wrap current column to WIDTH."
  (interactive (list (read-number "Enter column width: ")))
  (org-table-check-inside-data-field)
  (org-table-align)

  (let (cline (ccol (org-table-current-column)) new-row-count (more t))
    (org-table-goto-line 1)
    (org-table-goto-column ccol)

    (while more
      (setq cline (org-table-current-line))

      ;; Cut current field
      (org-table-copy-region (point) (point) 'cut)

      ;; Justify for width
      (setq org-table-clip 
            (mapcar 'list (org-wrap (caar org-table-clip) width nil)))

      ;; Add new lines and fill
      (setq new-row-count (1- (length org-table-clip)))
      (if (> new-row-count 0)
          (org-table-insert-n-row-below new-row-count)) 
      (org-table-goto-line cline)
      (org-table-goto-column ccol)
      (org-table-paste-rectangle)
      (org-table-goto-line (+ cline new-row-count))

      ;; Move to next line
      (setq more (org-table-goto-line (+ cline new-row-count 1)))
      (org-table-goto-column ccol))

    (org-table-goto-line 1)
    (org-table-goto-column ccol)))

(defun org-table-insert-n-row-below (n)
  "Insert N new lines below the current."
  (let* ((line (buffer-substring (point-at-bol) (point-at-eol)))
         (new (org-table-clean-line line)))
    ;; Fix the first field if necessary
    (if (string-match "^[ \t]*| *[#$] *|" line)
        (setq new (replace-match (match-string 0 line) t t new)))
    (beginning-of-line 2)
    (setq new
      (apply 'concat (make-list n (concat new "\n"))))
    (let (org-table-may-need-update) (insert-before-markers new))  ;;; remove? 
    (beginning-of-line 0)
    (re-search-forward "| ?" (point-at-eol) t)
    (and (or org-table-may-need-update org-table-overlay-coordinates) ;;; remove? 
         (org-table-align))
    (org-table-fix-formulas "@" nil (1- (org-table-current-dline)) n)))


(setq org-src-tab-acts-natively t)
;; ============================================


;; ============= plantuml setup  ===============

(setq org-plantuml-jar-path
      (expand-file-name "/home/roy_miller/libraries/plantuml.jar"))
(org-babel-do-load-languages 'org-babel-load-languages '((plantuml . t)))


;; ============================================


;; ============== yaml setup ==================

(add-to-list 'load-path "~/.emacs.d/yaml-mode/")
(require 'yaml-mode)
(add-to-list 'auto-mode-alist '("\\.yml\\'" . yaml-mode))

(add-hook 'yaml-mode-hook
	'(lambda ()
	   (define-key yaml-mode-map "\C-m" 'newline-and-indent)))
;; ============================================


;; ================ gtd setup =================

(setq org-agenda-custom-commands
      '(
	("i" "IOT Agenda"
	 ((agenda "" ((org-agenda-files '("iot.org"))))
	  (tags "+IOT&+HIGH_PRIORITY+TODO=\"NEXT\"" ((org-agenda-overriding-header "High Priority Next Items : ")))
	  (tags "+IOT&+MEDIUM_PRIORITY+TODO=\"NEXT\"" ((org-agenda-overriding-header "Medium Priority Next Items : ")))
	  (tags "+IOT&+LOW_PRIORITY+TODO=\"NEXT\"" ((org-agenda-overriding-header "Low Priority Next Items : ")))
	  (tags "+IOT+TODO=\"DONE\"" ((org-agenda-overriding-header "Completed Items : ")))
	  (tags "+IOT+TODO=\"TODO\"" ((org-agenda-overriding-header "All TODO Items : ")))
	  (tags "+IOT+TODO=\"WAITING\"" ((org-agenda-overriding-header "All TODO Items : ")))))
	("c" "Computer Science Learning Agenda"
	 ((agenda "" ((org-agenda-files '("compscience.org"))))
	  (tags "+COMP_SCIENCE&+PYTHON+TODO=\"NEXT\"" ((org-agenda-overriding-header "Learn Python : ")))
	  (tags "+COMP_SCIENCE&+NETWORKING+TODO=\"NEXT\"" ((org-agenda-overriding-header "Learn Networking : ")))
	  (tags "+COMP_SCIENCE&+LINUX+TODO=\"NEXT\"" ((org-agenda-overriding-header "Learn Linux : ")))
	  (tags "+COMP_SCIENCE&+MACHINE_LEARNING+TODO=\"NEXT\"" ((org-agenda-overriding-header "Learn ML / AI  : ")))
	  (tags "+COMP_SCIENCE&+SOFTWARE_ENGINEERING+TODO=\"NEXT\"" ((org-agenda-overriding-header "Learn software engineering  : ")))
	  (tags "+COMP_SCIENCE&+EMACS+TODO=\"NEXT\"" ((org-agenda-overriding-header "Learn emacs  : ")))        	  
	  (tags "+COMP_SCIENCE&+MATHEMATICS+TODO=\"NEXT\"" ((org-agenda-overriding-header "Learn maths  : ")))        	  
	  (tags "+COMP_SCIENCE&+ESPRESSO+TODO=\"NEXT\"" ((org-agenda-overriding-header "Enjoy Coffee  : ")))
	  (tags "+COMP_SCIENCE+TODO=\"DONE\"" ((org-agenda-overriding-header "Completed Items : ")))
	  (tags "+COMP_SCIENCE+TODO=\"TODO\"" ((org-agenda-overriding-header "All TODO Items : ")))
	  (tags "+COMP_SCIENCE+TODO=\"SOMEDAY\"" ((org-agenda-overriding-header "All SOMEDAY Items : ")))))	  
	("p" "Personal Agenda"
	 ((agenda "" ((org-agenda-files '("personal.org"))))
	  (tags-todo "+PERSONAL&+BOOKS|+PHILOSOPHY" ((org-agenda-overriding-header "Books to read : ")))
	  (tags-todo "+PERSONAL&+ESPRESSO" ((org-agenda-overriding-header "Enjoy coffee : ")))
	  (tags-todo "+PERSONAL&+WEALTH" ((org-agenda-overriding-header "Be fucking rich : ")))
	  (tags-todo "+PERSONAL&+HOME" ((org-agenda-overriding-header "Make home : ")))))
	("f" "FPL Agenda"
	 ((agenda "" ((org-agenda-files '("fpl.org"))))
	  (tags-todo "+FPL" ((org-agenda-overriding-header "Win the fucking fantasy : ")))))))

;; ============================================

