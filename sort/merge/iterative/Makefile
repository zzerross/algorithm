CFLAGS := -Werror
# CFLAGS += -Wall

define build
$(eval 
$(2): FORCE $(1)
	clang-format --style=google -i $(3)
	g++ $(CFLAGS) -o $$@ $(3) -fconcepts
	time ./$(2) $(4) 2>&1 | tee $(2).txt
	@echo

OUTS += $(2)
)
endef

$(call build,main,lambda,lambda.cc,)
$(call build,,main,main.cc,)

clean:
	rm -rf $(OUTS)

.PHONY: FORCE

reset:
	find ! -name Makefile | xargs rm -rf

