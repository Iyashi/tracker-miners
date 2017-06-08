sources = [
    'tracker-main.c',
    'tracker-config.c',
    'tracker-daemon.c',
    'tracker-dbus.c',
    'tracker-extract.c',
    'tracker-help.c',
    'tracker-index.c',
    'tracker-info.c',
    'tracker-process.c',
    'tracker-reset.c',
    'tracker-search.c',
    'tracker-sparql.c',
    'tracker-sql.c',
    'tracker-status.c',
    'tracker-tag.c',
]

executable('tracker', sources,
    c_args: [
        '-DLIBEXECDIR="@0@"'.format(join_paths(get_option('prefix'), get_option('libexecdir'))),
        '-DMANDIR="@0@"'.format(join_paths(get_option('prefix'), get_option('datadir'), 'man')),
        '-DTRACKER_EXTRACTOR_RULES_DIR="@0@"'.format(tracker_extract_rules_dir),
        '-DTRACKER_COMPILATION',
    ],
    install: true,
    install_rpath: tracker_internal_libs_dir,
    # This doesn't depend on tracker_common_dep because of
    # https://github.com/mesonbuild/meson/issues/671
    dependencies: [tracker_control_dep, tracker_sparql_dep, tracker_data_dep],
    include_directories: [commoninc, configinc, srcinc],
)


if install_bash_completion
    install_data(
        sources: 'bash-completion/tracker',
        install_dir: bash_completion_dir)
endif