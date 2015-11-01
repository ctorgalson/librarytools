<?php

/**
 * @file
 * Provides theme-related functions required by librarytools module.
 */

/**
 * Theme function for list of dependencies.
 */
function theme_librarytools_dependencies($variables) {
  if (!empty($variables['dependencies'])) {
    $output = t('<div class="admin-required">Requires: !dependencies</div>', array('!dependencies' => implode(', ', $variables['dependencies'])));
  }
  else {
    $output = '';
  }

  return $output;
}

/**
 * Theme function for individual dependency.
 */
function theme_librarytools_dependency($variables) {
  return sprintf('%s (<span class="%s">%s</span>)', $variables['dependency_name'], $variables['class_name'], $variables['status']);
}

/**
 * Theme function for various repeated titles.
 */
function theme_librarytools_title($variables) {
  return sprintf('<strong>%s</strong>', $variables['title']);
}
