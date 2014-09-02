import readline
def complete_type(text, state):
    for cmd in type_list:
        if cmd.startswith(text):
            if not state:
                return cmd
            else:
                state -= 1
readline.parse_and_bind("tab: complete")
readline.set_completer(complete_type)